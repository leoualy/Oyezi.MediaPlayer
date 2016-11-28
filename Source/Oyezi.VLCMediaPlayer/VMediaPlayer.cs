/***************************************************************************
 * 文件名:             VMediaPlayer.cs
 * 作者：              liuyuan
 * 日期：              2016-11-27
 * 描述：              包装VlcCore，实现视频的处理逻辑
 *                             视频输出到窗体或控件上，需要设置Win32/Win64 API生成的
 *                             句柄，加载到Winform控件或窗体上可以直接获取需要的句柄
 *                             WPF 也可以获取句柄，但是加载到界面上时，不易控制
 *                             暂时的解决方式是用WindowsFormsHost 嵌入Winform控件 添加到WPF中
 *                             
***************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Oyezi.VLCMediaPlayer
{
    public class VMediaPlayer
    {
        public event BufferingEventHandler OnBuffering;
        public VMediaPlayer()
        {
            VLCInterop.CreateVlcInstance();
        }

        /// <summary>
        /// MediaPlayer 视频显示的控件句柄,用于WinForm项目
        /// </summary>
        public IntPtr VLCAttachFormHandle
        {
            set
            {
                VLCInterop.SetDrawable(value);
            }
        }

        /// <summary>
        /// 播放视频
        /// </summary>
        /// <param name="url"></param>
        public void Play(string url)
        {
            VLCInterop.AttachBufferingCallback(OnBuffering);
            VLCInterop.CreateRemoteMedia(url);
            VLCInterop.Play();
        }

        /// <summary>
        /// 播放本地视频
        /// </summary>
        /// <param name="path">本地路径</param>
        public void PlayLocal(string path)
        {
            VLCInterop.AttachBufferingCallback(OnBuffering);
            VLCInterop.CreateLocalMedia(path);
            VLCInterop.Play();
        }

        /// <summary>
        /// 播放远程视频
        /// </summary>
        /// <param name="url">网络视频url</param>
        public void PlayRemote(string url)
        {
            VLCInterop.AttachBufferingCallback(OnBuffering);
            VLCInterop.CreateRemoteMedia(url);
            VLCInterop.Play();
        }

        /// <summary>
        /// 暂停视频的播放，调用两次则从当前位置开始
        /// </summary>
        public void Pause()
        {
            VLCInterop.Pause();
        }

        /// <summary>
        /// 销毁实例
        /// </summary>
        public void Destory()
        {
            VLCInterop.Destory();
        }

    }
}
