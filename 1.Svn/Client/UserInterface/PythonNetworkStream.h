//Find
		bool SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos);
		
///Change
#if defined(SAFEBOX_CHECKOUT_UPDATE)
		bool SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos, bool SelectPosAuto);
#else
		bool SendSafeBoxCheckoutPacket(BYTE bySafeBoxPos, TItemPos InventoryPos);
#endif

//Find
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos);
		
///Change
#if defined(SAFEBOX_CHECKOUT_UPDATE)
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos, bool SelectPosAuto);
#else
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos);
#endif