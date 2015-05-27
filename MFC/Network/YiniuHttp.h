
class CYiniuHttp
{
public:
	CYiniuHttp(void);
	~CYiniuHttp(void);

private:
	CInternetSession m_session;
	CHttpConnection* m_pConnection;
	CHttpFile* m_pFile;

	//�Ƿ���������̱߳�־
	BOOL m_bThreadTerminated;
	
	//�����߳� ID
	DWORD m_dwThreadId;

	//�����̶߳���
	CWinThread* m_pThread;

	//�Ƿ��Ѿ������̱߳�־
	BOOL m_bHadCreateThread;

	//POST ��������
	CStringA m_straFormData;

	//POST  ����ͷ
	CString m_strPostHeader;

	//����ʽ
	BOOL m_bIsGet;

private:
	//��ӡ�������Ϣ
	//void PrintErrorInfo(CInternetException* ex);

	//��ȡ��Ӧ��Ϣ������
	void GetRespondData(CString& strRespondData);

	//ˢ�½��棬�ȴ��߳��������
	void WaitForThreadCompletedRequest(HANDLE* dpHthread);

	//�����߳�
	static UINT __cdecl WorkerThreadProc( LPVOID pParam );

	//��������
	DWORD CYiniuHttp::SendRequest(const CString& strURI, CString& strRespondData);

public:

	//��ȡ��Ҫ���ӵķ����� ip ��ַ, �˿ڣ�Ĭ��Ϊ 80��
	BOOL ConnectToTheServer(const CString& strIP, const INTERNET_PORT port = 80);

	/*  ���� get ����
	 *  strURI Ϊ��Ҫ����� URI
	 *  ����ֵΪ ���� Get ������������Ӧ��״̬
	 *  ��ͨ�� strRespondData ������ȡ����Ӧ������
	 */
	DWORD Get(const CString& strURI, CString& strRespondData);

	//����������� POST ����
	DWORD Post(const CString& strURI, CString& strRespondData, CStringA& straFormData);

	//�ر����ӣ��ͷ���Դ�� �رչ����߳�
	void CloseConnection();
};
