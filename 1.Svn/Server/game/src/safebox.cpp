//Find
bool CSafebox::IsEmpty(DWORD dwPos, BYTE bSize)
{
	...
}

///Add
#if defined(SAFEBOX_CHECKOUT_UPDATE)
int CSafebox::GetEmptySafebox(BYTE size)
{
	for (unsigned int i = 0; m_pkGrid && i < m_pkGrid->GetSize(); i++)
		if (IsEmpty(i, size))
			return i;

	return -1;
}
#endif