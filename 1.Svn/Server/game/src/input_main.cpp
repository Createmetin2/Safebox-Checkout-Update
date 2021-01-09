//Find in void CInputMain::SafeboxCheckout(LPCHARACTER ch, const char * c_pData, bool bMall)
	if (!ch->IsEmptyItemGrid(p->ItemPos, pkItem->GetSize()))
		return;
		
///Add Above
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	if (p->SelectPosAuto)
	{
		int AutoPos = pkItem->IsDragonSoul() ? ch->GetEmptyDragonSoulInventory(pkItem) : ch->GetEmptyInventory(pkItem->GetSize());
		if (AutoPos == -1)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough space.");
			return;
		}
		p->ItemPos = TItemPos(pkItem->IsDragonSoul() ? DRAGON_SOUL_INVENTORY : INVENTORY, AutoPos);
	}
#endif

//Find in void CInputMain::SafeboxCheckin(LPCHARACTER ch, const char * c_pData)
	if (!pkSafebox || !pkItem)
		return;
		
///Add
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	if (p->SelectPosAuto)
	{
		int AutoPos = pkSafebox->GetEmptySafebox(pkItem->GetSize());
		if (AutoPos == -1)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "<SAFEBOX> You don't have enough space.");
			return;
		}
		p->bSafePos = AutoPos;
	}
#endif