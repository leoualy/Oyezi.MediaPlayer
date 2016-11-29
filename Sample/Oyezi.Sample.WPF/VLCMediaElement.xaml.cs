

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Oyezi.VLCMediaPlayer;

namespace Oyezi.Sample.WPF
{
    /// <summary>
    /// VLCMediaElement.xaml 的交互逻辑
    /// </summary>
    public partial class VLCMediaElement : UserControl
    {
        private System.Windows.Forms.Panel mPnlMedia;
        private VMediaPlayer mMediaPlayer;
        public event BufferingEventHandler OnBuffered;
        public VLCMediaElement()
        {
            InitializeComponent();
            mPnlMedia = new System.Windows.Forms.Panel();
            mMediaPlayer = new VMediaPlayer();
            frmHost.Child = mPnlMedia;
            mMediaPlayer.OnBuffering += mMediaPlayer_OnBuffering;
            mMediaPlayer.OnEnded += mMediaPlayer_OnEnded;
            mMediaPlayer.VLCAttachFormHandle = mPnlMedia.Handle;
        }

        void mMediaPlayer_OnEnded()
        {
            MessageBox.Show("结束");
            // throw new NotImplementedException();
        }

        public void PlayLocal(string path)
        {
            mMediaPlayer.PlayLocal(path);
        }
        public void PlayRemote(string url)
        {
            mMediaPlayer.PlayRemote(url);
        }
        public void Pause()
        {
            mMediaPlayer.Pause();
        }

        void mMediaPlayer_OnBuffering(float newCache)
        {
            // throw new NotImplementedException();
            OnBuffered(newCache);
            
        }
    }
}
