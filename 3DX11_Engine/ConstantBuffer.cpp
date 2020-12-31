#include "ConstantBuffer.h"
#include "RenderSystem.h"
#include "DeviceContext.h"

ConstantBuffer::ConstantBuffer(RenderSystem *system) : m_system(system)
{
}

bool ConstantBuffer::load(void * buffer, UINT size_buffer)
{
	if (m_buffer)m_buffer->Release();

	D3D11_BUFFER_DESC buff_desc = {};
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	buff_desc.ByteWidth = size_buffer;
	buff_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA init_data = {};
	init_data.pSysMem = buffer;

	if (FAILED(m_system->m_d3d_device->CreateBuffer(&buff_desc, &init_data, &m_buffer)))
	{
		return false;
	}

	return true;
}

void ConstantBuffer::update(DeviceContext * context, void * buffer)
{
	context->m_device_context->UpdateSubresource(this->m_buffer, NULL, NULL, buffer, NULL, NULL);
}

bool ConstantBuffer::release()
{
	if (m_buffer)m_buffer->Release();
	delete this;
	return true;
}


ConstantBuffer::~ConstantBuffer()
{
}