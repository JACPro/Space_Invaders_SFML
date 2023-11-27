#include "BitmapStore.h"
#include <assert.h>

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(std::string const& filename)
{
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	auto keyValuePair = bitmapsMap.find(filename);

	// If no match found, save the texture in the map
	if (keyValuePair == bitmapsMap.end())
	{
		// Create a new key value pair using the filename
		auto& texture = bitmapsMap[filename];
		texture.loadFromFile(filename);
	}
}

sf::Texture& BitmapStore::getBitmap(std::string const& filename)
{
	auto& m = m_s_Instance->m_BitmapsMap;
	auto keyValuePair = m.find(filename);

	// If we found a kvp, otherwise crash
	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
#ifdef debuggingOnConsole
		cout << "ERROR in BitmapStore::getBitmap(): Texture not found" << endl;
#endif
		return keyValuePair->second;
	}
}
