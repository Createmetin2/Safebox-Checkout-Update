#Find in def UseItemSlot(self, slotIndex):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			if self.wndDragonSoulRefine.IsShow():
				self.wndDragonSoulRefine.AutoSetItem((player.INVENTORY, slotIndex), 1)
				return
				
#Add
		if app.SAFEBOX_CHECKOUT_UPDATE:
			if self.wndSafeBox.IsShow() and slotIndex < player.EQUIPMENT_SLOT_START:
				net.SendSafeboxCheckinPacket(slotIndex)
				return
				
#Find
	def SetDragonSoulRefineWindow(self, wndDragonSoulRefine):
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoulRefine = wndDragonSoulRefine
			
#Add
	if app.SAFEBOX_CHECKOUT_UPDATE:
		def SetSafeboxWindow(self, wndSafeBox):
			self.wndSafeBox = wndSafeBox