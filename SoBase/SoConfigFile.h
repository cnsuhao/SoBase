//------------------------------------------------------------
#ifndef _SoConfigFile_h_
#define _SoConfigFile_h_
//------------------------------------------------------------
#include <string>
#include <map>
//------------------------------------------------------------
class SoConfigFile
{
public:
	SoConfigFile();
	~SoConfigFile();

	//从磁盘上加载并解析指定的文件。
	//如果该文件并不存在，则表示加载了一个空文件，当执行WriteFile()时就写入这个文件。
	//--pFileName 文件名。其值不能为NULL。
	void ReadFile(const char* pFileName);

	//把当前的配置信息写入文件中。
	//在析构函数中会主动调用一次这个函数。
	void WriteFile();

	//根据指定的Key，获取相应的Value。如果Key不存在，则返回给定的默认值。
	int GetValue_int(const std::string& strKey, const int nDefaultValue);
	float GetValue_float(const std::string& strKey, const float fDefaultValue);
	const char* GetValue_string(const std::string& strKey, const char* pszDefaultValue);

	//填充新的键值对。如果给定的Key已经存在，则更新相应的Value的值。
	void SetValue_int(const std::string& strKey, const int nValue);
	void SetValue_float(const std::string& strKey, const float fValue);
	void SetValue_string(const std::string& strKey, const std::string& strValue);

private:
	//清除所有的成员变量。
	void ClearConfig();

	//解析文件中的一个数据块，读取出每一行的数据。
	//--bEndOfFile 是否已经读到了文件结尾。
	void ParseFileChunk(const char* pBuff, const int nValidSize, const bool bEndOfFile);

	//把文件中的一行数据解析出键值对。
	void ParseFileLine();

	//把字符串句首和句尾的某些字符剔除掉，剔除掉的字符包括空格，Tab字符。
	//--pBuff 字符串
	//--nValidSize 字符串有效字符个数
	//--nAdjustStartIndex [out] 字符串在pBuff中的起始地址。传入时此值为0，函数内部会调整这个值。
	void SlimString(char* pBuff, int nValidSize, int& nAdjustStartIndex);

private:
	typedef std::map<std::string, std::string> mapKey2Value;

private:
	//存储文件名。包括完整路径。
	std::string m_strFileName;
	//存储键值对。
	mapKey2Value m_mapKey2Value;

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//加载并解析磁盘文件时会使用到下面这些成员。
	//存储文件中一行的数据。
	char* m_pFileLineBuff;
	//当前m_pFileLineBuff中的有效长度。
	int m_nValidLineSize;
	//文件中的一行包括“键字符串”和“值字符串”。
	//这个值表示“键字符串”在m_pFileLineBuff中的首地址。
	int m_nKeyStartIndex;
	//这个值表示“值字符串”在m_pFileLineBuff中的首地址。
	int m_nValueStartIndex;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//记录键值对是否发生了变化。
	//如果没有发生变化，则在WriteFile()时不会真的执行写操作。
	bool m_bDirty;
};
//------------------------------------------------------------
#endif //_SoConfigFile_h_
//------------------------------------------------------------
