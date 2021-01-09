//Find in void CInputMain::SafeboxCheckout(LPCHARACTER ch, const char * c_pData, bool bMall)
	LPITEM pkItem = pkSafebox->Get(p->bSafePos);

	if (!pkItem)
		return;
		
///Add
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	if (p->SelectPosAuto)
	{
		if (pkItem->IsDragonSoul())
			p->ItemPos = TItemPos(DRAGON_SOUL_INVENTORY, ch->GetEmptyDragonSoulInventory(pkItem));
		else
			p->ItemPos = TItemPos(INVENTORY, ch->GetEmptyInventory(pkItem->GetSize()));
	}
#endif