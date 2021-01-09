#Find(2x)
	def UseItemSlot(self, slotIndex):
		mouseModule.mouseController.DeattachObject()
		
#Add(2x)
		if app.SAFEBOX_CHECKOUT_UPDATE:
			net.SendSafeboxCheckoutPacket(slotIndex)