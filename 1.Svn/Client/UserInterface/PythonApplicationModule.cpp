//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(SAFEBOX_CHECKOUT_UPDATE)
	PyModule_AddIntConstant(poModule, "SAFEBOX_CHECKOUT_UPDATE", true);
#else
	PyModule_AddIntConstant(poModule, "SAFEBOX_CHECKOUT_UPDATE", false);
#endif