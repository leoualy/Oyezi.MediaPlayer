#include "VlcCore.h"
#pragma comment(lib,"libvlc")


CoreAPI int CreateVlcInstance(){
	return (pVlcInstance = libvlc_new(0, NULL)) != NULL ? 0 : -1;
}

CoreAPI void SetDrawable(void *hwnd){
	pDrawable = hwnd;
}


CoreAPI void CreateLocalMedia(const char *path){
	if (pMedia == NULL){
		pMedia = libvlc_media_new_path(pVlcInstance, path);
	}
}

CoreAPI void CreateRemoteMedia(const char *url){
	if (pMedia == NULL){
		pMedia = libvlc_media_new_location(pVlcInstance, url);
	}
}

CoreAPI void Play(){
	if (pMediaPlayer == NULL){
		pMediaPlayer = libvlc_media_player_new_from_media(pMedia);
	}
	libvlc_media_player_set_hwnd(pMediaPlayer, pDrawable);
	if (pVLCEventManager == NULL){
		pVLCEventManager = libvlc_media_player_event_manager(pMediaPlayer);
	}
	libvlc_event_attach(pVLCEventManager, libvlc_MediaPlayerBuffering, OnBuffering, NULL);
	libvlc_media_player_play(pMediaPlayer);

	return;
}


CoreAPI void Pause(){
	libvlc_media_player_pause(pMediaPlayer);
}

CoreAPI int Destory(){
	libvlc_media_player_release(pMediaPlayer);
	libvlc_media_release(pMedia);
	libvlc_release(pVlcInstance);
	return 0;
}

void OnBuffering(const struct libvlc_event_t *pEvent, void * value){
	float newCache = pEvent->u.media_player_buffering.new_cache;
	pfunBuffingCallback(newCache);
}

CoreAPI void AttachBufferingCallback(BuffingCallback pBuffingCallback){
	pfunBuffingCallback = pBuffingCallback;
}


