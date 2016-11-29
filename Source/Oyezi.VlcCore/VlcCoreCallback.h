#ifndef HEAD_H
#define HEAD_H
#include "export_head.h"
#endif

#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif

// MediaPlayer事件管理器指针
libvlc_event_manager_t *pVLCMediaPlayerEventManager; 
// Media 事件管理器指针
libvlc_event_manager_t *pVLCMediaEventManager;                       

void OnStateChanged(libvlc_state_t state);
void OnVLCEventCallback(const struct libvlc_event_t *pEvent, void * value);

void attach_media_events(libvlc_media_t *pMedia);
void attach_media_player_events(libvlc_media_player_t *pMediaPlayer);

/**
*缓冲事件回调的函数指针类型
*参数 newCahce 当前缓冲的进度
*/
typedef void(*BuffingCallback)(float newCache);
// 缓冲事件回调函数指针
BuffingCallback pfunBuffingCallback;
CoreAPI void AttachBufferingCallback(BuffingCallback pBuffingCallback);

typedef void(*EndedCallback)();
// 播放结束事件的回调函数指针
EndedCallback pfunEndedCallback;
CoreAPI void AttachEndedCallback(EndedCallback pEndedCallback);





