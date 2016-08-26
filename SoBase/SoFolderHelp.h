//------------------------------------------------------------
#ifndef _SoFolderHelp_h_
#define _SoFolderHelp_h_
//------------------------------------------------------------
#include <string>
#include <vector>
//------------------------------------------------------------
class SoFolderHelp
{
public:
	
	//��·������ת����ͳһת��ΪСд��ת��\\Ϊ/��Ȼ����·����ĩβ����/��
	//ͬʱ��Ҫȥ��ͷ����'.'��'/'
	static void ConvertPathName(const char* filePath, std::string& convertedFilePath);

	//����ָ�����ļ��м������ļ��У����ļ������������·�����洢��vector�ڡ�
	//--pMainPath �ļ���·��������'/'��β����������Ч·����
	//--pSubPath ��ֵ����ΪNULL�������ΪNULL����ʾҪ�������ļ���Ϊ pMainPath+pSubPath ��·��������'/'��β��
	//--vecFiles ����ֵ
	static void ScanFolder(const char* pMainPath, const char* pSubPath, std::vector<std::string>& vecFiles);
};
//------------------------------------------------------------
#endif //_SoFolderHelp_h_
//------------------------------------------------------------
