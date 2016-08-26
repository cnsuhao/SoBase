//------------------------------------------------------------
#ifndef _SoImageHelp_h_
#define _SoImageHelp_h_
//------------------------------------------------------------
//图片文件类型，目前只支持PNG图片
enum SoImageFileType
{
	SoImageFileType_Invalid = -1, //无效值
	SoImageFileType_PNG, //PNG图片
};
//------------------------------------------------------------
//色彩位深，每个颜色通道占据几个bit。
//目前只支持 RGBA 32位色，每个通道占8位。
enum SoImageBitDepthType
{
	SoImageBitDepth_Invalid = -1, //无效值
	SoImageBitDepth_8,
};
//------------------------------------------------------------
//图片颜色类型，目前只支持32位的RGBA颜色
enum SoImageColorType
{
	SoImageColorType_Invalid = -1, //无效值
	SoImageColorType_RGBA, //RGB颜色，含alpha通道
};
//------------------------------------------------------------
//图片信息
struct SoImageFileInfo
{
	int nWidth; //图片宽度
	int nHeight; //图片高度
	SoImageFileType theFileType;
	SoImageBitDepthType theBitDepth; //色彩位深，目前只支持32位色
	SoImageColorType theColorType; //颜色类型，目前只支持RGBA颜色
	unsigned char* pData; //存储图片文件中的图像数据。在 SoImageHelp::LoadImage() 函数内部为其申请内存，但是该内存的释放由外界负责。

	SoImageFileInfo();
};
//------------------------------------------------------------
class SoImageHelp
{
public:
	//从磁盘上加载指定的图片文件。
	//--pszFileName 图片文件名，包含路径。
	//--pImageInfo [out] 获取图片文件的各个数据。
	//加载成功返回true，否则返回false。
	//函数内部会申请内存，用于存储图像数据，但是该内存的释放由外界负责。
	static bool LoadImageFile(const char* pszFileName, SoImageFileInfo* pImageInfo);

private:
	//检测文件的类型。
	static SoImageFileType CheckFileType(const char* pszFileName);

};
//------------------------------------------------------------
#endif //_SoImageHelp_h_
//------------------------------------------------------------
