//Find
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos)
{
	...
}

///Change
#if defined(SAFEBOX_CHECKOUT_UPDATE)
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos, bool SelectPosAuto)
#else
bool CPythonNetworkStream::SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos)
#endif
{
	__PlaySafeBoxItemDropSound(bySafeBoxPos);

	TPacketCGSafeboxCheckout kSafeboxCheckout;
	kSafeboxCheckout.bHeader = HEADER_CG_SAFEBOX_CHECKOUT;
	kSafeboxCheckout.bSafePos = bySafeBoxPos;
	kSafeboxCheckout.ItemPos = InventoryPos;
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	kSafeboxCheckout.SelectPosAuto = SelectPosAuto;
#endif
	if (!Send(sizeof(kSafeboxCheckout), &kSafeboxCheckout))
		return false;

	return SendSequence();
}

//Find
bool CPythonNetworkStream::SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos)
{
	...
}

///Change
#if defined(SAFEBOX_CHECKOUT_UPDATE)
bool CPythonNetworkStream::SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos, bool SelectPosAuto)
#else
bool CPythonNetworkStream::SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos)
#endif
{
	__PlayMallItemDropSound(byMallPos);

	TPacketCGMallCheckout kMallCheckoutPacket;
	kMallCheckoutPacket.bHeader = HEADER_CG_MALL_CHECKOUT;
	kMallCheckoutPacket.bMallPos = byMallPos;
	kMallCheckoutPacket.ItemPos = InventoryPos;
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	kMallCheckoutPacket.SelectPosAuto = SelectPosAuto;
#endif
	if (!Send(sizeof(kMallCheckoutPacket), &kMallCheckoutPacket))
		return false;

	return SendSequence();
}