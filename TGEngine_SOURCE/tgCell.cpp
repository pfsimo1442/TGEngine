#include "tgCell.h"
#include "tgApplication.h"
#include "tgResources.h"

extern tg::Application application;

namespace tg
{
	Cell* Cell::Create(const std::wstring& name, UINT size)
	{
		Cell* cell = Resources::Find<Cell>(name);
		if (cell)
			return cell;

		cell = new Cell();
		cell->SetName(name);
		cell->SetSize(size);

		Resources::Insert(name + L"Cell", cell);

		return cell;
	}

	Cell::Cell()
		: Resource(enums::eResourceType::Cell)
		, mSize(0)
	{
	}
	Cell::~Cell()
	{
	}
}