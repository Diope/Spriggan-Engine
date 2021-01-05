#pragma once
#include "Vector3D.h"
#include "Vector2D.h"

class VertexMesh
{
public:
	VertexMesh() :m_position(), m_texcoord()
	{
	}
	VertexMesh(Vector3D m_position, Vector2D m_texcoord) :m_position(m_position), m_texcoord(m_texcoord)
	{
	}
	VertexMesh(const VertexMesh& vertex) :m_position(vertex.m_position), m_texcoord(vertex.m_texcoord)
	{
	}

	~VertexMesh()
	{
	}

public:
	Vector3D m_position;
	Vector2D m_texcoord;
};