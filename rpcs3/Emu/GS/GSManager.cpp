#include "stdafx.h"
#include "Utilities/Log.h"
#include "Emu/Memory/Memory.h"
#include "rpcs3/Ini.h"

#include "GSManager.h"
#include "Null/NullGSRender.h"
#include "GL/GLGSRender.h"

GSManager::GSManager() : m_render(nullptr)
{
}

void GSManager::Init()
{
	if(m_render) return;

	m_info.Init();

	switch(Ini.GSRenderMode.GetValue())
	{
	default:
	case 0: m_render = new NullGSRender(); break;
	case 1: m_render = new GLGSRender(); break;
	}
	//m_render->Init(GetInfo().outresolution.width, GetInfo().outresolution.height);
}

void GSManager::Close()
{
	if(m_render)
	{
		m_render->Close();
		delete m_render;
		m_render = nullptr;
	}
}

u8 GSManager::GetState()
{
	return CELL_VIDEO_OUT_OUTPUT_STATE_ENABLED;
}

u8 GSManager::GetColorSpace()
{
	return CELL_VIDEO_OUT_COLOR_SPACE_RGB;
}
