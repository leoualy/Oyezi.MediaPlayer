#include "VlcCoreCallback.h"

extern libvlc_media_player_t *pVLCMediaPlayer;
extern libvlc_media_t *pVLCMedia;


void OnVLCEventCallback(const struct libvlc_event_t *pEvent, void * value)
{
	int eventType = pEvent->type;
	switch (eventType)
	{
	// 处理缓冲事件
	case libvlc_MediaPlayerBuffering:
		pfunBuffingCallback(pEvent->u.media_player_buffering.new_cache); break;
	// media 状态改变	
	case libvlc_MediaStateChanged:
		OnStateChanged(pEvent->u.media_state_changed.new_state); break;
	default:
		break;
	}
}

void OnStateChanged(libvlc_state_t state)
{
	int mState = state;
	switch (mState)
	{
	case libvlc_Ended:
		libvlc_media_release(pVLCMedia);
		pVLCMedia = NULL;
		pfunEndedCallback(); break;
	default:
		break;
	}
}



CoreAPI void AttachBufferingCallback(BuffingCallback pBuffingCallback)
{
	pfunBuffingCallback = pBuffingCallback;
}
CoreAPI void AttachEndedCallback(EndedCallback pEndedCallback)
{
	pfunEndedCallback = pEndedCallback;
}

void attach_media_events(libvlc_media_t *pMedia)
{
	pVLCMediaEventManager = libvlc_media_event_manager(pVLCMedia);
	// 添加视频状态变化事件
	libvlc_event_attach(pVLCMediaEventManager, libvlc_MediaStateChanged, OnVLCEventCallback, NULL);
}

void attach_media_player_events(libvlc_media_player_t *pMediaPlayer)
{
	pVLCMediaPlayerEventManager = libvlc_media_player_event_manager(pMediaPlayer);
	// 添加视频缓冲事件
	libvlc_event_attach(pVLCMediaPlayerEventManager, libvlc_MediaPlayerBuffering, OnVLCEventCallback, NULL);
}