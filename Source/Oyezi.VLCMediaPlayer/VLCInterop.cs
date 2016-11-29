/***************************************************************************
 * 文件名:             VLCInterop.cs
 * 作者：              liuyuan
 * 日期：              2016-11-27
 * 描述：              导入非托管函数
***************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Oyezi.VLCMediaPlayer
{
    internal class VLCInterop
    {
        /// <summary>
        /// 创建LibVlc 实例
        /// </summary>
        /// <returns></returns>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern int CreateVlcInstance();

        /// <summary>
        /// 设置视频输出的承载窗体
        /// </summary>
        /// <param name="hwnd"></param>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void SetDrawable(IntPtr hwnd);

        /// <summary>
        /// 创建本地Media
        /// </summary>
        /// <param name="url"></param>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void CreateLocalMedia(string path);

        /// <summary>
        /// 创建网络Media
        /// </summary>
        /// <param name="url"></param>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void CreateRemoteMedia(string url);

        /// <summary>
        /// 播放视频
        /// </summary>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void Play();

        /// <summary>
        /// 暂停 调用两次即可从当前位置播放
        /// </summary>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void Pause();

        /// <summary>
        /// 释放全部实例
        /// </summary>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void Destory();

        /// <summary>
        /// 向Libvlc 注册回调处理
        /// </summary>
        /// <param name="onBuffingCallback"></param>
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void AttachBufferingCallback(BufferingEventHandler onBuffingCallback);
        [DllImport("Oyezi.VlcCore.dll")]
        internal static extern void AttachEndedCallback(EndedEventHandler onEndedCallback);
    }
}
