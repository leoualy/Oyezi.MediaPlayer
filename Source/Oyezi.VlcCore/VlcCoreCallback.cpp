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
		pfunBuffingCallback(pEvent->u.media_player_buffering.new_cache+5); break;
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