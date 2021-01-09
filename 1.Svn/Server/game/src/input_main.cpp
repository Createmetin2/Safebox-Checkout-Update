//Find in void CInputMain::SafeboxCheckout(LPCHARACTER ch, const char * c_pData, bool bMall)
	if (!ch->IsEmptyItemGrid(p->ItemPos, pkItem->GetSize()))
		return;
		
///Change
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	if (p->SelectPosAuto)
	{
		if (pkItem->IsDragonSoul())
			p->ItemPos = TItemPos(DRAGON_SOUL_INVENTORY, ch->GetEmptyDragonSoulInventory(pkItem));
		else
			p->ItemPos = TItemPos(INVENTORY, ch->GetEmptyInventory(pkItem->GetSize()));
	}
	if (!ch->IsEmptyItemGrid(p->ItemPos, pkItem->GetSize()))
	{
		if (p->SelectPosAuto)
			ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough space.");
		return;
	}
#else
	if (!ch->IsEmptyItemGrid(p->ItemPos, pkItem->GetSize()))
		return;
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