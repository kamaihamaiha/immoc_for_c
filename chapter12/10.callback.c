/**
 * 案例：并发任务执行与函数回调
 * 有点复杂
 */
#include "tinycthread.h"
#include <io_utils_teacher.h>
#include "time_utils.h"

#define DOWNLOAD_TASK 5

// 定义下载的参数类型
typedef struct Context {
  mtx_t mutex; //锁，保护未下载的任务数量
  int download_left; // 未下载的任务数量
} Context;

/**
 * 下载请求结构体
 */
typedef struct DownloadRequest {
  Context *context;
  char const *url; // 下载地址
  char const *filename; // 下载后，保存的文件名
  int progress; // 下载进度
  int interval; // 模拟下载的一个参数, 线程下载的间隔时间
  void (*callback)(struct DownloadRequest *); // 下载完成后的一个回调参数
} DownloadRequest;

/**
 * 下载文件
 * @param download_request
 * @return
 */
int DownloadFile(DownloadRequest *download_request) {
  // 先打印一下下载的文件信息。 \r 让光标回到行首
  PRINTLNF("\rDownloading file form: %s to %s ...", download_request->url, download_request->filename);

  // 模拟下载进度
  for (int i = 0; i < 100; ++i) {
    download_request->progress = i;
    SleepMs(download_request->interval);
  }

  // 下载完成后，返回结果
  download_request->callback(download_request);
  return 0;
}

/**
 * 下载回调函数
 * @param request
 */
void DownloadCallback(DownloadRequest *request) {
  mtx_lock(&request->context->mutex); // 加锁
  request->context->download_left--;
  PRINTLNF("\rDownload file form: %s into %s successfully, left: %d",
           request->url,
           request->filename,
           request->context->download_left
  );

  mtx_unlock(&request->context->mutex); // 解锁
}

int main() {

  char *urls[] = {
      "https://www.bennyhuo.com/file1",
      "https://www.bennyhuo.com/file2",
      "https://www.bennyhuo.com/file3",
      "https://www.bennyhuo.com/file4",
      "https://www.bennyhuo.com/file5",
  };

  char *files[] = {
      "download/file1",
      "download/file2",
      "download/file3",
      "download/file4",
      "download/file5",
  };

  // 下载请求数组
  DownloadRequest requests[DOWNLOAD_TASK];

  // 多个下载任务共用一个下载上下文
  Context context = {.download_left = DOWNLOAD_TASK};

  // 初始化线程
  mtx_init(&context.mutex, mtx_plain);

  // 下载请求参数初始化, 然后下载
  for (int i = 0; i < DOWNLOAD_TASK; ++i) {
    requests[i] = (DownloadRequest) {
        .context = &context, // 多个下载任务共用一个下载上下文
        .url = urls[i],
        .filename = files[i],
        .progress = 0,
        .interval = i * 50 + 100,
        .callback = DownloadCallback
    };

    thrd_t t;
    thrd_create(&t, DownloadFile, &requests[i]);
    thrd_detach(t);
  }

  // 主线程读取下载任务进度
  while (1) {
    mtx_lock(&context.mutex); // 加锁
    int download_left = context.download_left;
    mtx_unlock(&context.mutex); // 解锁

    if (download_left == 0) { // 下载结束
      break;
    }

    printf("\r");
    for (int i = 0; i < DOWNLOAD_TASK; ++i) {
      printf("%s --- %3d%% ", requests[i].filename, requests[i].progress);
    }

    // 写到控制台
    fflush(stdout);

    SleepMs(100);
  }

  mtx_destroy(&context.mutex);

  return 0;
}