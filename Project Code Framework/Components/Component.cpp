#include "Component.h"

GraphicsInfo Component::getGraphicsinfo()
{
	return m_GfxInfo;
}

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	mSelected = false;
}


void Component::SetSelected(bool s)
{
	mSelected = s;
}
bool Component::IsSelected() const {
	return mSelected;
}


Component::Component()
{}

Component::~Component()
{}

