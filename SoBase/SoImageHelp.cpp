//------------------------------------------------------------
#include "SoImageHelp.h"
#include <string.h>
//------------------------------------------------------------
SoImageFileInfo::SoImageFileInfo()
:nWidth(0)
,nHeight(0)
,theFileType(SoImageFileType_Invalid)
,theBitDepth(SoImageBitDepth_Invalid)
,theColorType(SoImageColorType_RGBA)
,pData(0)
{

}
//------------------------------------------------------------
bool SoImageHelp::LoadImageFile(const char* pszFileName, SoImageFileInfo* pImageInfo)
{
	if (pszFileName == 0)
	{
		return false;
	}
	if (pImageInfo == 0)
	{
		return false;
	}
	//
	SoImageFileType theFileType = CheckFileType(pszFileName);
	if (theFileType == SoImageFileType_Invalid)
	{
		return false;
	}
	else if (theFileType == SoImageFileType_PNG)
	{
		return false;
	}

	return false;
}
//------------------------------------------------------------
SoImageFileType SoImageHelp::CheckFileType(const char* pszFileName)
{
	const SoImageFileType InvalidType = SoImageFileType_Invalid;

	if (pszFileName == 0)
	{
		return InvalidType;
	}
	//
	int nLen = (int)strlen(pszFileName);
	//图片文件的扩展名是3个字节，如果文件名的字符串长度小于等于3，则认为文件名不合法。
	if (nLen <= 3)
	{
		return InvalidType;
	}
	//判断是否为PNG图片
	if (pszFileName[nLen-3] == 'p' || pszFileName[nLen-3] == 'P')
	{
		if (pszFileName[nLen-2] == 'n' || pszFileName[nLen-2] == 'N')
		{
			if (pszFileName[nLen-1] == 'g' || pszFileName[nLen-1] == 'G')
			{
				return SoImageFileType_PNG;
			}
		}
	}

	return InvalidType;
}
//------------------------------------------------------------
