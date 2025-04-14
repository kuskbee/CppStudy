#pragma once

template <typename T>
class Vector2
{
public:
	T X;
	T Y;
};

template <typename T>
class Color
{
public:
	T R;
	T G;
	T B;
};

class Pixel
{
public:
	Vector2<int> Pos;
	Color<float> Color;
};

class Image
{
public:
	Vector2<int> Size;
	Pixel* ColorTable;
};
