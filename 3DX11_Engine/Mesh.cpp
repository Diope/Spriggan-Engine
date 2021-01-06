#include "Mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
#include <locale>
#include <codecvt>

#include "GraphicsEngine.h"
#include "VertexMesh.h"

Mesh::Mesh(const wchar_t *full_path): Resource(full_path)
{
	tinyobj::attrib_t attributes;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string warn;
	std::string err;

	std::string inputFile = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(full_path);

	bool res = tinyobj::LoadObj(&attributes, &shapes, &materials, &warn, &err, inputFile.c_str());

	if (!err.empty()) throw std::exception("Mesh was not loaded successfully.");
	if (!res) throw std::exception("Mes was not loaded succesfully");
	if (shapes.size() > 1) throw std::exception("Obj file contains more than one shape");

	std::vector<VertexMesh> list_vertices;
	std::vector<unsigned int> list_indices;

	for (size_t s = 0; s < shapes.size(); s++)
	{
		size_t index_offset = 0;
		list_vertices.reserve(shapes[s].mesh.indices.size());
		list_indices.reserve(shapes[s].mesh.indices.size());

		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
		{
			unsigned char num_face_verts = shapes[s].mesh.num_face_vertices[f];

			for (unsigned char v = 0; v < num_face_verts; v++)
			{
				//TODO: Holy **** this is an O(n^3) operation, there HAS to be a better way to do this...
				tinyobj::index_t index = shapes[0].mesh.indices[index_offset + v];

				// Vertices
				tinyobj::real_t vx = attributes.vertices[index.vertex_index * 3 + 0];
				tinyobj::real_t vy = attributes.vertices[index.vertex_index * 3 + 1];
				tinyobj::real_t vz = attributes.vertices[index.vertex_index * 3 + 2];

				// Texture coordinates
				tinyobj::real_t tx = attributes.texcoords[index.texcoord_index * 2 + 0];
				tinyobj::real_t ty = attributes.texcoords[index.texcoord_index * 2 + 1];

				// Normals
				tinyobj::real_t nx = attributes.normals[index.normal_index * 3 + 0];
				tinyobj::real_t ny = attributes.normals[index.normal_index * 3 + 1];
				tinyobj::real_t nz = attributes.normals[index.normal_index * 3 + 2];

				VertexMesh vertex(Vector3D(vx, vy, vz), Vector2D(tx, ty), Vector3D(nx, ny, nz));
				list_vertices.push_back(vertex);

				list_indices.push_back(index_offset + v);
			}
			index_offset += num_face_verts;
		}
	}

	void* shader_byte_code = nullptr;
	size_t size_shader = 0;
	GraphicsEngine::get()->getVertexMeshLayoutShaderByteCodeAndSize(&shader_byte_code, &size_shader);
	m_vertex_buffer = GraphicsEngine::get()->getRenderSystem()->createVertexBuffer(&list_vertices[0],
		sizeof(VertexMesh), (UINT)list_vertices.size(), shader_byte_code, (UINT)size_shader);

	m_index_buffer = GraphicsEngine::get()->getRenderSystem()->createIndexBuffer(&list_indices[0], (UINT)list_indices.size());
}


Mesh::~Mesh()
{
}

const VertexBufferPtr & Mesh::getVertexBuffer()
{
	return m_vertex_buffer;
}

const IndexBufferPtr & Mesh::getIndexBuffer()
{
	return m_index_buffer;
}
