# Brings the WowClient64 game window ("Waystone") to the front and saves a screenshot of it: shot_game.ps1 <out.png>
param([string]$Out = 'D:\GODOT\Projects\WILDSTAR-Decomp\docs\_shot2.png')
Add-Type @"
using System; using System.Text; using System.Runtime.InteropServices;
public class WG { public delegate bool EP(IntPtr h, IntPtr l); [DllImport("user32.dll")] static extern bool EnumWindows(EP cb, IntPtr l); [DllImport("user32.dll")] static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid); [DllImport("user32.dll")] static extern int GetWindowText(IntPtr h, StringBuilder s, int n); [DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr h, IntPtr a, int x,int y,int cx,int cy,uint f); [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h,int c); [DllImport("user32.dll")] public static extern bool BringWindowToTop(IntPtr h);
 public static IntPtr Find(uint pid){ IntPtr r=IntPtr.Zero; EnumWindows((h,l)=>{ uint p; GetWindowThreadProcessId(h,out p); if(p==pid){ var sb=new StringBuilder(256); GetWindowText(h,sb,256); if(sb.ToString()=="Waystone") r=h;} return true;}, IntPtr.Zero); return r; } }
"@
$p = Get-Process WowClient64 -ErrorAction Stop | Select -First 1
$h = [WG]::Find([uint32]$p.Id)
[WG]::ShowWindow($h, 9) | Out-Null
[WG]::SetWindowPos($h, [IntPtr](-1), 100, 40, 0, 0, 0x0041) | Out-Null
[WG]::BringWindowToTop($h) | Out-Null
Start-Sleep 2
Add-Type -AssemblyName System.Windows.Forms, System.Drawing
$b = [System.Windows.Forms.SystemInformation]::VirtualScreen
$bmp = New-Object System.Drawing.Bitmap $b.Width, $b.Height
$g = [System.Drawing.Graphics]::FromImage($bmp)
$g.CopyFromScreen($b.X, $b.Y, 0, 0, $bmp.Size)
$bmp.Clone((New-Object System.Drawing.Rectangle (100 - $b.X), 40, 1030, 780), $bmp.PixelFormat).Save($Out)
