#pragma once
#include "Vector3D.h"
#include "Vector2D.h"

class VertexMesh
{
public:
	VertexMesh() :m_position(), m_texcoord(), m_normal()
	{
	}
	VertexMesh(Vector3D m_position, Vector2D m_texcoord, Vector3D m_normal) : 
		m_position(m_position), 
		m_texcoord(m_texcoord), 
		m_normal(m_normal)
	{
	}
	VertexMesh(const VertexMesh& vertex) : 
		m_position(vertex.m_position), 
		m_texcoord(vertex.m_texcoord), 
		m_normal(vertex.m_normal)
	{
	}

	~VertexMesh()
	{
	}

public:
	Vector3D m_position;
	Vector3D m_normal;
	Vector2D m_texcoord;

};