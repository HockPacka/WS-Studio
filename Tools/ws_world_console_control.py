"""Inspect/interrupt exactly the worldserver console; never force-terminate it."""
import argparse,ctypes,json,os
p=argparse.ArgumentParser();p.add_argument('pid',type=int);p.add_argument('--interrupt',action='store_true');p.add_argument('--launcher-pid',type=int,default=0);a=p.parse_args();k=ctypes.WinDLL('kernel32',use_last_error=True)
k.FreeConsole()
if not k.AttachConsole(a.pid):raise ctypes.WinError(ctypes.get_last_error())
k.SetConsoleCtrlHandler(None,True)
ids=(ctypes.c_uint32*64)();count=k.GetConsoleProcessList(ids,64);members=list(ids[:count]);safe=set(members)<={a.pid,os.getpid(),a.launcher_pid}
result=dict(server=a.pid,helper=os.getpid(),members=members,safe=safe,interrupted=False)
if a.interrupt:
 if not safe:raise RuntimeError('Shared console contains other processes; cannot safely signal it')
 if not k.GenerateConsoleCtrlEvent(0,0):raise ctypes.WinError(ctypes.get_last_error())
 result['interrupted']=True
k.FreeConsole();print(json.dumps(result))
