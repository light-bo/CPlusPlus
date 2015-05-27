
class CYiniuHttp
{
public:
	CYiniuHttp(void);
	~CYiniuHttp(void);

private:
	CInternetSession m_session;
	CHttpConnection* m_pConnection;
	CHttpFile* m_pFile;

	//是否结束工作线程标志
	BOOL m_bThreadTerminated;
	
	//工作线程 ID
	DWORD m_dwThreadId;

	//工作线程对象
	CWinThread* m_pThread;

	//是否已经创建线程标志
	BOOL m_bHadCreateThread;

	//POST 请求数据
	CStringA m_straFormData;

	//POST  请求头
	CString m_strPostHeader;

	//请求方式
	BOOL m_bIsGet;

private:
	//打印错误的信息
	//void PrintErrorInfo(CInternetException* ex);

	//获取响应消息的数据
	void GetRespondData(CString& strRespondData);

	//刷新界面，等待线程完成请求
	void WaitForThreadCompletedRequest(HANDLE* dpHthread);

	//工作线程
	static UINT __cdecl WorkerThreadProc( LPVOID pParam );

	//发送请求
	DWORD CYiniuHttp::SendRequest(const CString& strURI, CString& strRespondData);

public:

	//获取所要连接的服务器 ip 地址, 端口（默认为 80）
	BOOL ConnectToTheServer(const CString& strIP, const INTERNET_PORT port = 80);

	/*  发送 get 请求
	 *  strURI 为所要请求的 URI
	 *  返回值为 发送 Get 请求后服务器响应的状态
	 *  可通过 strRespondData 参数获取到响应的数据
	 */
	DWORD Get(const CString& strURI, CString& strRespondData);

	//向服务器发送 POST 请求
	DWORD Post(const CString& strURI, CString& strRespondData, CStringA& straFormData);

	//关闭连接，释放资源， 关闭工作线程
	void CloseConnection();
};
