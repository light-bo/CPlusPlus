//全局状态下获取窗口的句柄
AfxGetApp()->GetMainWnd()->m_hWnd


//产生 worker thread
Data data;
...
...
CWinThread = AfxBeginThread(WorkerThreadProc, &data);


