#pragma once

class Colour
{
public:
	unsigned int dword;
public:
	constexpr Colour() : dword() {}
	constexpr Colour( const Colour& col )
		:
		dword( col.dword )
	{}
	constexpr Colour( unsigned int dw )
		:
		dword( dw )
	{}
	constexpr Colour( unsigned char x,unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (x << 24u) | (r << 16u) | (g << 8u) | b )
	{}
	constexpr Colour( unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (r << 16u) | (g << 8u) | b )
	{}
	constexpr Colour( Colour col,unsigned char x )
		:
		Colour( (x << 24u) | col.dword )
	{}
	Colour& operator =( Colour colour )
	{
		dword = colour.dword;
		return *this;
	}
	constexpr unsigned char GetX() const
	{
		return dword >> 24u;
	}
	constexpr unsigned char GetA() const
	{
		return GetX();
	}
	constexpr unsigned char GetR() const
	{
		return (dword >> 16u) & 0xFFu;
	}
	constexpr unsigned char GetG() const
	{
		return (dword >> 8u) & 0xFFu;
	}
	constexpr unsigned char GetB() const
	{
		return dword & 0xFFu;
	}
	void SetX( unsigned char x )
	{
		dword = (dword & 0xFFFFFFu) | (x << 24u);
	}
	void SetA( unsigned char a )
	{
		SetX( a );
	}
	void SetR( unsigned char r )
	{
		dword = (dword & 0xFF00FFFFu) | (r << 16u);
	}
	void SetG( unsigned char g )
	{
		dword = (dword & 0xFFFF00FFu) | (g << 8u);
	}
	void SetB( unsigned char b )
	{
		dword = (dword & 0xFFFFFF00u) | b;
	}
};

namespace Colours
{
	static constexpr Colour MakeRGB( unsigned char r,unsigned char g,unsigned char b )
	{
		return (r << 16) | (g << 8) | b;
	}
	static constexpr Colour White = MakeRGB( 255u,255u,255u );
	static constexpr Colour Black = MakeRGB( 0u,0u,0u );
	static constexpr Colour Gray = MakeRGB( 0x80u,0x80u,0x80u );
	static constexpr Colour LightGray = MakeRGB( 0xD3u,0xD3u,0xD3u );
	static constexpr Colour Red = MakeRGB( 255u,0u,0u );
	static constexpr Colour Green = MakeRGB( 0u,255u,0u );
	static constexpr Colour Blue = MakeRGB( 0u,0u,255u );
	static constexpr Colour Yellow = MakeRGB( 255u,255u,0u );
	static constexpr Colour Cyan = MakeRGB( 0u,255u,255u );
	static constexpr Colour Magenta = MakeRGB( 255u,0u,255u );
}