/* Data of the menu unit, still to be merged into it. */
#include "common.h"

#ifdef DEATH_LABEL
extern u8 D_002620F0[];
extern u8 D_00262130[];
extern u8 D_00262170[];
extern u8 D_002621B0[];
extern u8 D_002621F0[];
extern u8 D_00282040[];
extern u8 D_00282050[];
extern u8 D_00282058[];
extern u8 D_00282068[];
extern u8 D_00282070[];
extern u8 D_00282080[];
extern u8 D_00282088[];
extern u8 D_00282090[];
extern u8 D_002820C0[];
extern u8 D_002820F0[];
extern u8 D_00282110[];
extern u8 D_00282140[];
extern u8 D_00282160[];
extern u8 D_00282180[];
extern u8 D_002821A0[];
extern u8 D_002821B8[];
extern u8 D_002821D0[];
extern u8 death_D_00282200[];
extern u8 D_00282230[];
extern u8 D_00282280[];
extern u8 D_002822B0[];
extern u8 D_002822C0[];
extern u8 D_002822D0[];
extern u8 D_002822E0[];
extern u8 D_002822F0[];
extern u8 D_00282300[];
extern u8 D_00282310[];
extern u8 D_00282320[];
extern u8 D_00282340[];
extern u8 D_00282360[];
extern u8 D_00282380[];
extern u8 D_002823A0[];
extern u8 D_002823C0[];
extern u8 D_002823E0[];
extern u8 D_002823E8[];
extern u8 D_002823F0[];
extern u8 D_002823F8[];
extern u8 D_00282418[];
extern u8 D_00282420[];
extern u8 D_00282428[];
extern u8 D_00282430[];
extern u8 D_00282438[];
extern u8 D_00282440[];
extern u8 D_00282448[];
extern u8 D_00282450[];
extern u8 D_00282458[];
extern u8 D_00282460[];
extern u8 D_00282468[];
extern u8 D_00282470[];
extern u8 D_00282478[];
extern u8 D_00282480[];
extern u8 D_00282488[];
extern u8 D_00282490[];
extern u8 D_00282498[];
extern u8 D_002824A0[];
extern u8 D_002824A8[];
extern u8 D_002824B0[];
extern u8 D_002824B8[];
extern u8 D_002824C0[];
extern u8 D_002824C8[];
extern u8 D_002824D0[];
extern u8 D_002824E0[];
extern u8 D_002824F0[];
extern u8 D_00282500[];
extern u8 D_00282510[];
extern u8 D_00282520[];
extern u8 D_00282530[];
extern u8 D_00282540[];
extern u8 D_00282550[];
extern u8 D_00282560[];
extern u8 D_00282570[];
extern u8 D_00282580[];
extern u8 D_00282590[];
extern u8 D_002825A0[];
extern u8 D_002825B0[];
extern u8 D_002825C0[];
extern u8 D_002825D0[];
extern u8 D_002825E0[];
extern u8 D_00282600[];
extern u8 D_002826A0[];
extern u8 D_002826C0[];
extern u8 D_002826F0[];
extern u8 D_00282730[];
extern u8 D_00282760[];
extern u8 D_002827B0[];
extern u8 D_00282800[];
extern u8 D_00282830[];
extern u8 D_00282838[];
extern u8 D_00282840[];
extern u8 D_00282848[];
extern u8 D_00282850[];
extern u8 D_00282858[];
extern u8 D_00282860[];
extern u8 D_00282868[];
extern u8 D_00282870[];
extern u8 D_00282878[];
extern u8 D_00282880[];
extern u8 D_00282888[];
extern u8 D_00282890[];
extern u8 D_00282898[];
extern u8 D_002828A0[];
extern u8 D_002828A8[];
extern u8 D_002828B0[];
extern u8 D_002828B8[];
extern u8 D_002828C0[];
extern u8 D_002828C8[];
extern u8 D_002828D0[];
extern u8 D_002828D8[];
extern u8 D_002828E0[];
extern u8 D_002828E8[];
extern u8 D_002828F0[];
extern u8 D_002828F8[];
extern u8 D_00282900[];
extern u8 D_00282908[];
extern u8 D_00282910[];
extern u8 D_00282918[];
extern u8 D_00282920[];
extern u8 D_00282928[];
extern u8 D_00282930[];
extern u8 D_00282938[];
extern u8 D_00282940[];
extern u8 D_00282948[];
extern u8 D_00282950[];
extern u8 D_00282958[];
extern u8 D_00282960[];
extern u8 D_00282968[];
extern u8 D_00282970[];
extern u8 D_00282978[];
extern u8 D_00282980[];
extern u8 D_00282988[];
extern u8 D_00282990[];
extern u8 D_00282998[];
extern u8 D_002829A0[];
extern u8 D_002829A8[];
extern u8 D_002829B0[];
extern u8 D_002829B8[];
extern u8 D_002829C0[];
extern u8 D_002829C8[];
extern u8 D_002829D0[];
extern u8 D_002829D8[];
extern u8 D_002829E0[];
extern u8 D_002829E8[];
extern u8 D_002829F0[];
extern u8 D_002829F8[];
extern u8 D_00282A00[];
extern u8 D_00282A08[];
extern u8 D_00282A10[];
extern u8 D_00282A18[];
extern u8 D_00282A20[];
extern u8 D_00282A28[];
extern u8 D_00282A30[];
extern u8 D_00282A38[];
extern u8 D_00282A40[];
extern u8 D_00282A48[];
extern u8 D_00282A50[];
extern u8 D_00282A58[];
extern u8 D_00282A60[];
extern u8 D_00282A68[];
extern u8 D_00282A70[];
extern u8 D_00282A78[];
extern u8 D_00282A80[];
extern u8 D_00282A88[];
extern u8 D_00282A90[];
extern u8 D_00282A98[];
extern u8 D_00282AA0[];
extern u8 D_00282AA8[];
extern u8 D_00282AB0[];
extern u8 D_00282AB8[];
extern u8 D_00282AC0[];
extern u8 D_00282AC8[];
extern u8 D_00282AD0[];
extern u8 D_00282AD8[];
extern u8 D_00282AE0[];
extern u8 D_00282AE8[];
extern u8 D_00282AF0[];
extern u8 D_00282AF8[];
extern u8 D_00282B00[];
extern u8 D_00282B08[];
extern u8 D_00282B10[];
extern u8 D_00282B18[];
extern u8 D_00282B20[];
extern u8 D_00282B28[];
extern u8 D_00282B30[];
extern u8 D_00282B38[];
extern u8 D_00282B40[];
extern u8 D_00282B48[];
extern u8 D_00282B50[];
extern u8 D_00282B58[];
extern u8 D_00282B60[];
extern u8 D_00282B68[];
extern u8 D_00282B70[];
extern u8 D_00282B78[];
extern u8 D_00282B80[];
extern u8 D_00282B88[];
extern u8 D_00282B90[];
extern u8 D_00282B98[];
extern u8 D_00282BA0[];
extern u8 D_00282BA8[];
extern u8 D_00282BB0[];
extern u8 D_00282BB8[];
extern u8 D_00282BC0[];
extern u8 D_00282BC8[];
extern u8 D_00282BD0[];
extern u8 D_00282BD8[];
extern u8 D_00282BE0[];
extern u8 D_00282BE8[];
extern u8 D_00282BF0[];
extern u8 D_00282BF8[];
extern u8 D_00282C00[];
extern u8 D_00282C08[];
extern u8 D_00282C10[];
extern u8 D_00282C18[];
extern u8 D_00282C20[];
extern u8 D_00282C28[];
extern u8 D_00282C30[];
extern u8 D_00282C38[];
extern u8 D_00282C40[];
extern u8 D_00282C48[];
extern u8 D_00282C50[];
extern u8 D_00282C58[];
extern u8 D_00282C60[];
extern u8 D_00282C68[];
extern u8 D_00282C70[];
extern u8 D_00282C78[];
extern u8 D_00282C80[];
extern u8 D_00282C88[];
extern u8 D_00282C90[];
extern u8 D_00282C98[];
extern u8 D_00282CA0[];
extern u8 D_00282CA8[];
extern u8 D_00282CB0[];
extern u8 D_00282CB8[];
extern u8 D_00282CC0[];
extern u8 D_00282CC8[];
extern u8 D_00282CD0[];
extern u8 D_00282CD8[];
extern u8 D_00282CE0[];
extern u8 D_00282CE8[];
extern u8 D_00282CF0[];
extern u8 D_00282CF8[];
extern u8 D_00282D00[];
extern u8 D_00282D08[];
extern u8 D_00282D10[];
extern u8 D_00282D18[];
extern u8 D_00282D20[];
extern u8 D_00282D28[];
extern u8 D_00282D30[];
extern u8 D_00282D38[];
extern u8 D_00282D40[];
extern u8 D_00282D48[];
extern u8 D_00282D50[];
extern u8 D_00282D58[];
extern u8 D_00282D60[];
extern u8 D_00282D68[];
extern u8 D_00282D70[];
extern u8 D_00282D78[];
extern u8 D_00282D80[];
extern u8 D_00282D88[];
extern u8 D_00282D90[];
extern u8 D_00282D98[];
extern u8 D_00282DA0[];
extern u8 D_00282DA8[];
extern u8 D_00282DB0[];
extern u8 D_00282DB8[];
extern u8 D_00282DC0[];
extern u8 D_00282DC8[];
extern u8 D_00282DD0[];
extern u8 D_00282DD8[];
extern u8 D_00282DE0[];
extern u8 D_00282DE8[];
extern u8 D_00282DF0[];
extern u8 D_00282DF8[];
extern u8 D_00282E00[];
extern u8 D_00282E08[];
extern u8 D_00282E10[];
extern u8 D_00282E18[];
extern u8 D_00282E20[];
extern u8 D_00282E28[];
extern u8 D_00282E30[];
extern u8 D_00282E38[];
extern u8 D_00282E40[];
extern u8 D_00282E48[];
extern u8 D_00282E50[];
extern u8 D_00282E58[];
extern u8 D_00282E60[];
extern u8 D_00282E68[];
extern u8 D_00282E70[];
extern u8 D_00282E78[];
extern u8 D_00282E80[];
extern u8 D_00282E88[];
extern u8 D_00282E90[];
extern u8 D_00282E98[];
extern u8 D_00282EA0[];
extern u8 D_00282EA8[];
extern u8 D_00282EB0[];
extern u8 D_00282EB8[];
extern u8 D_00282EC0[];
extern u8 D_00282EC8[];
extern u8 D_00282ED0[];
extern u8 D_00282ED8[];
extern u8 D_00282EE0[];
extern u8 D_00282EE8[];
extern u8 D_00282EF0[];
extern u8 D_00282EF8[];
extern u8 D_00282F00[];
extern u8 D_00282F08[];
extern u8 D_00282F10[];
extern u8 D_00282F18[];
extern u8 D_00282F20[];
extern u8 D_00282F28[];
extern u8 D_00282F30[];
extern u8 D_00282F38[];
extern u8 D_00282F40[];
extern u8 D_00282F48[];
extern u8 D_00282F50[];
extern u8 D_00282F58[];
extern u8 D_00282F60[];
extern u8 D_00282F68[];
extern u8 D_00282F70[];
extern u8 D_00282F78[];
extern u8 D_00282F80[];
extern u8 D_00282F88[];
extern u8 D_00282F90[];
extern u8 D_00282F98[];
extern u8 D_00282FA0[];
extern u8 D_00282FA8[];
extern u8 D_00282FB0[];
extern u8 D_00282FB8[];
extern u8 D_00282FC0[];
extern u8 D_00282FC8[];
extern u8 D_00282FD0[];
extern u8 D_00282FD8[];
extern u8 D_00282FE0[];
extern u8 D_00282FE8[];
extern u8 D_00282FF0[];
extern u8 D_00282FF8[];
extern u8 D_00283000[];
extern u8 D_00283008[];
extern u8 D_00283010[];
extern u8 D_00283018[];
extern u8 D_00283020[];
extern u8 D_00283028[];
extern u8 D_00283030[];
extern u8 D_00283038[];
extern u8 D_00283040[];
extern u8 D_00283048[];
extern u8 D_00283050[];
extern u8 D_00283058[];
extern u8 D_00283060[];
extern u8 D_00283068[];
extern u8 D_00283070[];
extern u8 D_00283078[];
extern u8 D_00283080[];
extern u8 D_00283088[];
extern u8 D_00283090[];
extern u8 D_00283098[];
extern u8 D_002830A0[];
extern u8 D_002830A8[];
extern u8 D_002830B0[];
extern u8 D_002830B8[];
extern u8 D_002830C0[];
extern u8 D_002830C8[];
extern u8 D_002830D0[];
extern u8 D_002830D8[];
extern u8 D_002830E0[];
extern u8 D_002830E8[];
extern u8 D_002830F0[];
extern u8 D_002830F8[];
extern u8 D_00283100[];
extern u8 D_00283108[];
extern u8 D_00283110[];
extern u8 D_00283118[];
extern u8 D_00283120[];
extern u8 D_00283128[];
extern u8 D_00283130[];
extern u8 D_00283138[];
extern u8 D_00283140[];
extern u8 D_00283148[];
extern u8 D_00283150[];
extern u8 D_00283158[];
extern u8 D_00283160[];
extern u8 D_00283168[];
extern u8 D_00283170[];
extern u8 D_00283178[];
extern u8 D_00283180[];
extern u8 D_00283188[];
extern u8 D_00283190[];
extern u8 D_00283198[];
extern u8 D_002831A0[];
extern u8 D_002831A8[];
extern u8 D_002831B0[];
extern u8 D_002831B8[];
extern u8 D_002831C0[];
extern u8 D_002831C8[];
extern u8 D_002831D0[];
extern u8 D_002831D8[];
extern u8 D_002831E0[];
extern u8 D_002831E8[];
extern u8 D_002831F0[];
extern u8 D_002831F8[];
extern u8 D_00283200[];
extern u8 D_00283208[];
extern u8 D_00283210[];
extern u8 D_00283218[];
extern u8 D_00283220[];
extern u8 D_00283228[];
extern u8 D_00283230[];
extern u8 D_00283238[];
extern u8 D_00283240[];
extern u8 D_00283248[];
extern u8 D_00283258[];
extern u8 D_00283260[];
extern u8 D_00283268[];
extern u8 D_00283278[];
extern u8 D_00283280[];
extern u8 D_00283288[];
extern u8 D_00283290[];
extern u8 D_00283298[];
extern u8 D_002832A0[];
extern u8 D_002832A8[];
extern u8 D_002832B0[];
extern u8 D_002832B8[];
extern u8 D_002832C0[];
extern u8 D_002832C8[];
extern u8 D_002832D0[];
extern u8 D_002832D8[];
extern u8 D_002832E0[];
extern u8 D_002832E8[];
extern u8 D_002832F0[];
extern u8 D_002832F8[];
extern u8 D_00283300[];
extern u8 D_00283308[];
extern u8 D_00283310[];
extern u8 D_00283318[];
extern u8 D_00283320[];
extern u8 D_00283328[];
extern u8 D_00283330[];
extern u8 D_00283338[];
extern u8 D_00283340[];
extern u8 D_00283348[];
extern u8 D_00283350[];
extern u8 D_00283358[];
extern u8 D_00283360[];
extern u8 D_00283368[];
extern u8 D_00283370[];
extern u8 D_00283378[];
extern u8 D_00283380[];
extern u8 D_00283388[];
extern u8 D_00283390[];
extern u8 D_00283398[];
extern u8 D_002833A0[];
extern u8 D_002833A8[];
extern u8 D_002833B8[];
extern u8 D_002833C0[];
extern u8 D_002833C8[];
extern u8 D_002833D0[];
extern u8 D_002833D8[];
extern u8 D_002833E0[];
extern u8 D_002833E8[];
extern u8 D_002833F0[];
extern u8 D_002833F8[];
extern u8 D_00283400[];
extern u8 D_00283408[];
extern u8 D_00283410[];
extern u8 D_00283418[];
extern u8 D_00283420[];
extern u8 D_00283428[];
extern u8 D_00283430[];
extern u8 D_00283438[];
extern u8 D_00283440[];
extern u8 D_00283448[];
extern u8 D_00283450[];
extern u8 D_00283458[];
extern u8 D_00283460[];
extern u8 D_00283468[];
extern u8 D_00283470[];
extern u8 D_00283478[];
extern u8 D_00283480[];
extern u8 D_00283488[];
extern u8 D_00283490[];
extern u8 D_00283498[];
extern u8 D_002834A0[];
extern u8 D_002834A8[];
extern u8 D_002834B0[];
extern u8 D_002834B8[];
extern u8 D_002834C0[];
extern u8 D_002834C8[];
extern u8 D_002834D0[];
extern u8 D_002834D8[];
extern u8 D_002834E0[];
extern u8 D_002834E8[];
extern u8 D_002834F0[];
extern u8 D_002834F8[];
extern u8 D_00283500[];
extern u8 D_00283508[];
extern u8 D_00283510[];
extern u8 D_00283518[];
extern u8 D_00283520[];
extern u8 D_00283528[];
extern u8 D_00283530[];
extern u8 D_00283538[];
extern u8 D_00283540[];
extern u8 D_00283548[];
extern u8 D_00283550[];
extern u8 D_00283558[];
extern u8 D_00283560[];
extern u8 D_00283568[];
extern u8 D_00283570[];
extern u8 D_00283578[];
extern u8 D_00283580[];
extern u8 D_00283588[];
extern u8 D_00283590[];
extern u8 D_00283598[];
extern u8 D_002835A0[];
extern u8 D_002835A8[];
extern u8 D_002835B0[];
extern u8 D_002835B8[];
extern u8 D_002835C0[];
extern u8 D_002835C8[];
extern u8 D_002835D0[];
extern u8 D_002835D8[];
extern u8 D_002835E0[];
extern u8 D_002835E8[];
extern u8 D_002835F0[];
extern u8 D_002835F8[];
extern u8 D_00283600[];
extern u8 D_00283608[];
extern u8 D_00283610[];
extern u8 D_00283618[];
extern u8 D_00283620[];
extern u8 D_00283628[];
extern u8 D_00283630[];
extern u8 D_00283638[];
extern u8 D_00283640[];
extern u8 D_00283648[];
extern u8 D_00283650[];
extern u8 D_00283658[];
extern u8 D_00283660[];
extern u8 D_00283668[];
extern u8 D_00283670[];
extern u8 D_00283678[];
extern u8 D_00283680[];
extern u8 D_00283688[];
extern u8 D_00283690[];
extern u8 D_00283698[];
extern u8 D_002836A0[];
extern u8 D_002836A8[];
extern u8 D_002836B0[];
extern u8 D_002836B8[];
extern u8 D_002836C0[];
extern u8 D_002836C8[];
extern u8 D_002836D0[];
extern u8 D_002836D8[];
extern u8 D_002836E0[];
extern u8 D_002836E8[];
extern u8 D_002836F0[];
extern u8 D_002836F8[];
extern u8 D_00283700[];
extern u8 D_00283708[];
extern u8 D_00283710[];
extern u8 D_00283718[];
extern u8 D_00283720[];
extern u8 D_00283728[];
extern u8 D_00283730[];
extern u8 D_00283738[];
extern u8 D_00283740[];
extern u8 D_00283748[];
extern u8 D_00283750[];
extern u8 D_00283758[];
extern u8 D_00283760[];
extern u8 D_00283768[];
extern u8 D_00283770[];
extern u8 D_00283778[];
extern u8 D_00283780[];
extern u8 D_00283788[];
extern u8 D_00283790[];
extern u8 D_00283798[];
extern u8 D_002837A0[];
extern u8 D_002837A8[];
extern u8 D_002837B0[];
extern u8 D_002837B8[];
extern u8 D_002837C0[];
extern u8 D_002837C8[];
extern u8 D_002837D0[];
extern u8 D_002837D8[];
extern u8 D_002837E0[];
extern u8 D_002837F0[];
extern u8 D_00283810[];
extern u8 D_00283820[];
extern u8 D_00283830[];
extern u8 D_00283840[];
extern u8 D_00283850[];
extern u8 D_00283860[];
extern u8 D_00283870[];
extern u8 D_002838A0[];
extern u8 D_002838C0[];
extern u8 D_002838F0[];
extern u8 D_00283910[];
extern u8 D_00283930[];
extern u8 D_00283988[];
extern u8 D_00283998[];
extern u8 D_002839A8[];
extern u8 D_002839B8[];
extern u8 D_002839C8[];
extern u8 D_002839D8[];
extern u8 D_002839E8[];
extern u8 D_002839F8[];
extern u8 D_00283A08[];
extern u8 D_00283A18[];
extern u8 D_00283AC0[];
extern u8 D_00283AE0[];
extern u8 D_00283B00[];
extern u8 D_00283B20[];
extern u8 D_00283B40[];
extern u8 D_00283B60[];
extern u8 D_00283B80[];
extern u8 D_00283BA0[];
extern u8 D_00283BC0[];
extern u8 D_00283BE0[];
extern u8 D_00283C08[];
extern u8 D_00283C18[];
extern u8 D_00283C28[];
extern u8 D_00283C30[];
extern u8 D_00283C40[];
extern u8 D_00283C50[];
extern u8 D_00283C60[];
extern u8 D_00283C70[];
extern u8 D_00283C80[];
extern u8 D_00283C90[];
extern u8 D_00283C98[];
extern u8 D_00283CA8[];
extern u8 D_00283CB0[];
extern u8 D_00283CB8[];
extern u8 D_00283CC8[];
extern u8 D_00283CD0[];
extern u8 D_00283CE0[];
extern u8 D_00283CF0[];
extern u8 D_00283D00[];
extern u8 D_00283D10[];
extern u8 D_00283D20[];
extern u8 D_00283D30[];
extern u8 D_00283D40[];
extern u8 D_00283D50[];
extern u8 D_00283D60[];
extern u8 D_00283D70[];
extern u8 D_00283D80[];
extern u8 D_00283D90[];
extern u8 D_00283DA0[];
extern u8 D_00283DB0[];
extern u8 D_00283DC0[];
extern u8 D_00283DD0[];
extern u8 D_00283DE0[];
extern u8 D_00283DF0[];
extern u8 D_00283E00[];
extern u8 D_00283E20[];
extern u8 D_00283E40[];
extern u8 D_00283E60[];
extern u8 D_00283E78[];
extern u8 D_00283E80[];
extern u8 D_00283E90[];
extern u8 D_00283EB0[];
extern u8 D_00283ED0[];
extern u8 D_00283EF0[];
extern u8 D_00283F10[];
extern u8 D_00283F30[];
extern u8 D_00283F50[];
extern u8 D_00283F68[];
extern u8 D_00283F78[];
extern u8 D_00283F80[];
extern u8 D_00283F88[];
extern u8 D_00283F98[];
extern u8 D_00283FD0[];
extern u8 D_00283FD8[];
extern u8 D_00283FE0[];
extern u8 D_00283FE8[];
extern u8 D_00283FF0[];
extern u8 D_00283FF8[];
extern u8 D_00284000[];
extern u8 D_00284008[];
extern u8 D_00284010[];
extern u8 D_00284018[];
extern u8 D_00284020[];
extern u8 D_00284028[];
extern u8 D_00284030[];
extern u8 D_00284038[];
extern u8 D_00284048[];
extern u8 D_00284070[];
extern u8 D_00284090[];
extern u8 D_002840C0[];
extern u8 D_002840F0[];
extern u8 D_00284120[];
extern u8 D_00284150[];
extern u8 D_00284180[];
extern u8 D_002841A0[];
extern u8 D_00284220[];
extern u8 D_00284250[];
extern u8 D_00284280[];
extern u8 D_002842B0[];
extern u8 D_002842D0[];
extern u8 D_002842F0[];
extern u8 D_00284320[];
extern u8 D_00284360[];
extern u8 D_002843A0[];
extern u8 D_002843C0[];
extern u8 D_002843F0[];
extern u8 D_00284430[];
extern u8 D_00284460[];
extern u8 D_00284490[];
extern u8 D_002844C0[];
extern u8 D_002844E0[];
extern u8 D_00284510[];
extern u8 D_00284540[];
extern u8 D_00284570[];
extern u8 D_002845A0[];
extern u8 D_002845C0[];
extern u8 D_00284610[];
extern u8 D_00284640[];
extern u8 D_00284670[];
extern u8 D_002847B0[];
extern u8 D_002847D0[];
extern u8 D_002847F0[];
extern u8 D_00284810[];
extern u8 D_00284860[];
extern u8 D_00284880[];
extern u8 D_00284888[];
extern u8 D_002848A0[];
extern u8 D_002848C0[];
extern u8 D_002848E0[];
extern u8 D_00284AF8[];
extern u8 D_00284B10[];
extern u8 D_00284C28[];
extern u8 D_00284C30[];
extern u8 D_00284C38[];
extern u8 D_00284C40[];
extern u8 D_0028DCC8[];
extern u8 D_0028FF80[];
extern u8 D_0028FF98[];
extern u8 D_0028FFA0[];
extern u8 D_0028FFB0[];
extern u8 D_0028FFB8[];
extern u8 D_0028FFBC[];
extern u8 death_D_00282050[];
extern u8 death_D_00282058[];
extern u8 death_D_00282430[];
extern u8 death_D_00282438[];
extern u8 death_D_00282440[];
extern u8 death_D_00282448[];
extern u8 death_D_00282450[];
extern u8 death_D_00282458[];
extern u8 death_D_00282460[];
extern u8 death_D_00282468[];
extern u8 death_D_00282470[];
extern u8 death_D_00282650[];
extern u8 death_D_00283250[];
extern u8 death_D_00283270[];
extern u8 death_D_002833B0[];

extern s32 D_00270810[6];
extern u16 D_00270828[7];
extern u16 D_00270838[7];
struct D00270850Record { void *p0[6]; u16 w1[4]; };
extern struct D00270850Record D_00270850;
struct D00270870Record { void *p0[6]; u16 w1[4]; };
extern struct D00270870Record D_00270870;
struct D00270890Record { void *p0[6]; u16 w1[4]; };
extern struct D00270890Record D_00270890;
struct D002708b0Record { void *p0[6]; u16 w1[4]; };
extern struct D002708b0Record D_002708B0;
extern void *D_002708D0[8];
struct D002708f0Record { void *p0[15]; u16 w1[2]; };
extern struct D002708f0Record D_002708F0;
struct DeathD002622f0Record { void *p0[21]; u16 w1[6]; void *p2[8]; };
extern struct DeathD002622f0Record death_D_002622F0;
struct D002709b0Record { void *p0[5]; u16 w1[6]; };
extern struct D002709b0Record D_002709B0;
extern void *D_002709D0[12];
extern void *D_00270A00[12];
struct DeathD002623f0Record { void *p0[7]; u16 w1[2]; void *p2[9]; u16 w3[6]; void *p4[9]; u16 w5[6]; };
extern struct DeathD002623f0Record death_D_002623F0;
struct D00270ab0Record { void *p0[501]; u16 w1[6]; };
extern struct D00270ab0Record D_00270AB0;
struct D00271290Record { void *p0[9]; u16 w1[6]; };
extern struct D00271290Record D_00271290;
extern u16 D_002712C0[12];
extern s8 D_002712D8[14];
struct D002712f0Record { void *p0[9]; u16 w1[6]; };
extern struct D002712f0Record D_002712F0;
struct D00271320Record { void *p0[9]; u16 w1[2]; void *p2[3]; u16 w3[6]; void *p4[10]; u16 w5[4]; void *p6[21]; u16 w7[6]; void *p8[5]; u16 w9[6]; void *p10[10]; u16 w11[4]; };
extern struct D00271320Record D_00271320;
extern void *D_00271440[6];
extern u16 D_00271458[7];
extern s8 D_00271468[14];
extern void *D_00271480[12];
struct D002714b0Record { void *p0[15]; u16 w1[2]; };
extern struct D002714b0Record D_002714B0;
extern s8 D_002714F0[32];
struct D00271510Record { void *p0[7]; u16 w1[2]; };
extern struct D00271510Record D_00271510;
struct D00271540Record { void *p0[7]; u16 w1[2]; };
extern struct D00271540Record D_00271540;
struct D00271560Record { void *p0[7]; u16 w1[2]; };
extern struct D00271560Record D_00271560;
extern void *D_00271580[8];
struct D00271598Record { void *p0[3]; u16 w1[2]; };
extern struct D00271598Record D_00271598;
struct D002715b0Record { void *p0[6]; u16 w1[4]; };
extern struct D002715b0Record D_002715B0;
struct D002715d0Record { void *p0[14]; u16 w1[4]; };
extern struct D002715d0Record D_002715D0;
extern void *D_00271610[12];
extern void *death_D_00262FF0[4];
extern void *D_00271640[4];
struct D00271650Record { void *p0[5]; u16 w1[6]; };
extern struct D00271650Record D_00271650;
extern void *D_00271670[8];
extern s8 D_00271690[16];
extern s8 D_002716A0[16];
extern void *D_002716B0[4];
struct D002716c0Record { void *p0[6]; u16 w1[4]; };
extern struct D002716c0Record D_002716C0;
extern void *D_002716E0[10];
extern void *death_D_002630C8[3];
struct D00271710Record { void *p0[10]; u16 w1[4]; };
extern struct D00271710Record D_00271710;
struct D00271740Record { void *p0[6]; u16 w1[4]; };
extern struct D00271740Record D_00271740;
extern s16 D_00271760[32];
extern u16 D_002717A0[32];
extern s16 D_002717E0[16];
extern s16 D_00271800[136];
extern s32 D_00271910[64];
extern u16 D_00271A10[8];
struct D00271a20Record { void *p0[7]; u16 w1[2]; };
extern struct D00271a20Record D_00271A20;
struct D00271a50Record { void *p0[7]; u16 w1[2]; };
extern struct D00271a50Record D_00271A50;
struct D00271a70Record { void *p0[7]; u16 w1[2]; };
extern struct D00271a70Record D_00271A70;
extern void *D_00271A90[8];
struct D00271ab0Record { void *p0[6]; u16 w1[4]; };
extern struct D00271ab0Record D_00271AB0;
struct D00271ad0Record { void *p0[14]; u16 w1[4]; };
extern struct D00271ad0Record D_00271AD0;
extern void *death_D_002634D0[4];
struct D00271b30Record { void *p0[10]; u16 w1[4]; };
extern struct D00271b30Record D_00271B30;
struct D00271b90Record { void *p0[10]; u16 w1[4]; void *p2[2]; };
extern struct D00271b90Record D_00271B90;
extern void *D_00271BC8[3];
extern u8 D_00271BE0[128];
struct D00271c60Record { u16 w0[2]; void *p1; u16 w2[2]; void *p3; u16 w4[2]; void *p5; u16 w6[2]; void *p7; u16 w8[2]; void *p9; u16 w10[4]; };
extern struct D00271c60Record D_00271C60;
extern u16 D_00271C90[8];
extern u16 death_D_00263620[16];
struct D00271cc0Record { void *p0[3]; u16 w1[2]; };
extern struct D00271cc0Record D_00271CC0;
struct D00271cd0Record { void *p0[3]; u16 w1[2]; };
extern struct D00271cd0Record D_00271CD0;
extern s16 D_00271CE0[16];
extern void *D_00271D00[4];
extern void *D_00271D10[4];

s32 D_00270810[6] = {
    0, 393216, 8, 100, 0, 0,
};

u16 D_00270828[7] = {
    0x0001, 0x0000, 0x0000, 0x0014, 0x0000, 0x0000, 0x0000,
};

u16 D_00270838[7] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

struct D00270850Record D_00270850 = {
    {
        D_00282040,
        death_D_00282050,
        death_D_00282058,
        D_00282068,
        D_00282070,
        D_00282080,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270870Record D_00270870 = {
    {
        D_00282088,
        D_00282090,
        D_002820C0,
        D_002820F0,
        D_00282110,
        D_00282140,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270890Record D_00270890 = {
    {
        D_00282050,
        D_00282160,
        D_00282180,
        D_002821A0,
        D_002821B8,
        D_00282080,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D002708b0Record D_002708B0 = {
    {
        D_00282088,
        D_002821D0,
        death_D_00282200,
        D_00282230,
        D_00282280,
        D_00282140,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_002708D0[8] = {
    D_002822B0,
    D_002822C0,
    D_002822D0,
    D_002822E0,
    D_002822F0,
    D_00282300,
    D_00282310,
    D_00282080,
};

struct D002708f0Record D_002708F0 = {
    {
        D_00282088,
        D_00282320,
        D_00282340,
        D_00282360,
        D_00282380,
        D_002823A0,
        D_002823C0,
        D_00282140,
        D_002823E0,
        D_002823E8,
        D_002823F0,
        D_002823F8,
        D_00282418,
        D_00282420,
        D_00282428,
    },
    { 0x0000, 0x0000 },
};

struct DeathD002622f0Record death_D_002622F0 = {
    {
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        death_D_00282468,
        death_D_00282470,
        D_00282478,
        D_00282480,
        D_00282488,
        D_00282490,
        D_00282498,
        D_002824A0,
        D_002824A8,
        D_002824B0,
        D_002824B8,
        D_002824C0,
        D_002824C8,
        D_002824D0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002824E0,
        D_002824F0,
        D_00282500,
        D_00282510,
        D_00282520,
        D_00282530,
        D_00282540,
        D_00282540,
    },
};

struct D002709b0Record D_002709B0 = {
    {
        (u8 *)&D_002708F0 + 32,
        D_0028FF80,
        (u8 *)&D_002708F0 + 48,
        &death_D_002622F0,
        (u8 *)&death_D_002622F0 + 96,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_002709D0[12] = {
    D_00282180,
    D_00282550,
    D_00282560,
    D_00282570,
    D_00282580,
    D_00282590,
    D_002825A0,
    D_002825B0,
    D_002825C0,
    D_002825D0,
    D_00282310,
    D_00282080,
};

void *D_00270A00[12] = {
    D_00282088,
    D_002825E0,
    D_00282600,
    death_D_00282650,
    D_002826A0,
    D_002826C0,
    D_002826F0,
    D_00282730,
    D_00282760,
    D_002827B0,
    D_002823C0,
    D_00282140,
};

struct DeathD002623f0Record death_D_002623F0 = {
    {
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        D_00282310,
    },
    { 0x0000, 0x0000 },
    {
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        D_00282830,
        D_00282310,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        D_00282830,
        D_00282310,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270ab0Record D_00270AB0 = {
    {
        D_00282840,
        D_00282848,
        D_00282850,
        D_00282858,
        D_00282860,
        D_00282868,
        D_00282870,
        D_00282878,
        D_00282880,
        D_00282888,
        D_00282890,
        D_00282898,
        D_002828A0,
        D_002828A8,
        D_002828B0,
        D_002828B8,
        D_002828C0,
        D_002828C8,
        D_002828D0,
        D_002828D8,
        D_002828E0,
        D_002828E8,
        D_002828F0,
        D_002828F8,
        D_00282900,
        D_00282908,
        D_00282910,
        D_00282918,
        D_00282920,
        D_00282928,
        D_00282930,
        D_00282938,
        D_00282940,
        D_00282948,
        D_00282950,
        D_00282958,
        D_00282960,
        D_00282968,
        D_00282970,
        D_00282978,
        D_00282980,
        D_00282988,
        D_00282990,
        D_00282998,
        D_002829A0,
        D_002829A8,
        D_002829B0,
        D_002829B8,
        D_002829C0,
        D_002829C8,
        D_002829D0,
        D_002829D8,
        D_002829E0,
        D_002829E8,
        D_002829F0,
        D_002829F8,
        D_00282A00,
        D_00282A08,
        D_00282A10,
        D_00282A18,
        D_00282A20,
        D_00282A28,
        D_00282A30,
        D_00282A38,
        D_00282A40,
        D_00282A48,
        D_00282A50,
        D_00282A58,
        D_00282A60,
        D_00282A68,
        D_00282A70,
        D_00282A78,
        D_00282A80,
        D_00282A88,
        D_00282A90,
        D_00282A98,
        D_00282AA0,
        D_00282AA8,
        D_00282AB0,
        D_00282AB8,
        D_00282AC0,
        D_00282AC8,
        D_00282AD0,
        D_00282AD8,
        D_00282AE0,
        D_00282AE8,
        D_00282AF0,
        D_00282AF8,
        D_00282B00,
        D_00282B08,
        D_00282B10,
        D_00282B18,
        D_00282B20,
        D_00282B28,
        D_00282B30,
        D_00282B38,
        D_00282B40,
        D_00282B48,
        D_00282B50,
        D_00282B58,
        D_00282B60,
        D_00282B68,
        D_00282B70,
        D_00282B78,
        D_00282B80,
        D_00282B88,
        D_00282B90,
        D_00282B98,
        D_00282BA0,
        D_00282BA8,
        D_00282BB0,
        D_00282BB8,
        D_00282BC0,
        D_00282BC8,
        D_00282BD0,
        D_00282BD8,
        D_00282BE0,
        D_00282BE8,
        D_00282BF0,
        D_00282BF8,
        D_00282C00,
        D_00282C08,
        D_00282C10,
        D_00282C18,
        D_00282C20,
        D_00282C28,
        D_00282C30,
        D_00282C38,
        D_00282C40,
        D_00282C48,
        D_00282C50,
        D_00282C58,
        D_00282C60,
        D_00282C68,
        D_00282C70,
        D_00282C78,
        D_00282C80,
        D_00282C88,
        D_00282C90,
        D_00282C98,
        D_00282CA0,
        D_00282CA8,
        D_00282CB0,
        D_00282CB8,
        D_00282CC0,
        D_00282CC8,
        D_00282CD0,
        D_00282CD8,
        D_00282CE0,
        D_00282CE8,
        D_00282CF0,
        D_00282CF8,
        D_00282D00,
        D_00282D08,
        D_00282D10,
        D_00282D18,
        D_00282D20,
        D_00282D28,
        D_00282D30,
        D_00282D38,
        D_00282D40,
        D_00282D48,
        D_00282D50,
        D_00282D58,
        D_00282D60,
        D_00282D68,
        D_00282D70,
        D_00282D78,
        D_00282D80,
        D_00282D88,
        D_00282D90,
        D_00282D98,
        D_00282DA0,
        D_00282DA8,
        D_00282DB0,
        D_00282DB8,
        D_00282DC0,
        D_00282DC8,
        D_00282DD0,
        D_00282DD8,
        D_00282DE0,
        D_00282DE8,
        D_00282DF0,
        D_00282DF8,
        D_00282E00,
        D_00282E08,
        D_00282E10,
        D_00282E18,
        D_00282E20,
        D_00282E28,
        D_00282E30,
        D_00282E38,
        D_00282E40,
        D_00282E48,
        D_00282E50,
        D_00282E58,
        D_00282E60,
        D_00282E68,
        D_00282E70,
        D_00282E78,
        D_00282E80,
        D_00282E88,
        D_00282E90,
        D_00282E98,
        D_00282EA0,
        D_00282EA8,
        D_00282EB0,
        D_00282EB8,
        D_00282EC0,
        D_00282EC8,
        D_00282ED0,
        D_00282ED8,
        D_00282EE0,
        D_00282EE8,
        D_00282EF0,
        D_00282EF8,
        D_00282F00,
        D_00282F08,
        D_00282F10,
        D_00282F18,
        D_00282F20,
        D_00282F28,
        D_00282F30,
        D_00282F38,
        D_00282F40,
        D_00282F48,
        D_00282F50,
        D_00282F58,
        D_00282F60,
        D_00282F68,
        D_00282F70,
        D_00282F78,
        D_00282F80,
        D_00282F88,
        D_00282F90,
        D_00282F98,
        D_00282FA0,
        D_00282FA8,
        D_00282FB0,
        D_00282FB8,
        D_00282FC0,
        D_00282FC8,
        D_00282FD0,
        D_00282FD8,
        D_00282FE0,
        D_00282FE8,
        D_00282FF0,
        D_00282FF8,
        D_00283000,
        D_00283008,
        D_00283010,
        D_00283018,
        D_00283020,
        D_00283028,
        D_00283030,
        D_00283038,
        D_00283040,
        D_00283048,
        D_00283050,
        D_00283058,
        D_00283060,
        D_00283068,
        D_00283070,
        D_00283078,
        D_00283080,
        D_00283088,
        D_00283090,
        D_00283098,
        D_002830A0,
        D_002830A8,
        D_002830B0,
        D_002830B8,
        D_002830C0,
        D_002830C8,
        D_002830D0,
        D_002830D8,
        D_002830E0,
        D_002830E8,
        D_002830F0,
        D_002830F8,
        D_00283100,
        D_00283108,
        D_00283110,
        D_00283118,
        D_00283120,
        D_00283128,
        D_00283130,
        D_00283138,
        D_00283140,
        D_00283148,
        D_00283150,
        D_00283158,
        D_00283160,
        D_00283168,
        D_00283170,
        D_00283178,
        D_00283180,
        D_00283188,
        D_00283190,
        D_00283198,
        D_002831A0,
        D_002831A8,
        D_002831B0,
        D_002831B8,
        D_002831C0,
        D_002831C8,
        D_002831D0,
        D_002831D8,
        D_002831E0,
        D_002831E8,
        D_002831F0,
        D_002831F8,
        D_00283200,
        D_00283208,
        D_00283210,
        D_00283218,
        D_00283220,
        D_00283228,
        D_00283230,
        D_00283238,
        D_00283240,
        D_00283248,
        death_D_00283250,
        D_00283258,
        D_00283260,
        D_00283268,
        death_D_00283270,
        D_00283278,
        D_00283280,
        D_00283288,
        D_00283290,
        D_00283298,
        D_002832A0,
        D_002832A8,
        D_002832B0,
        D_002832B8,
        D_002832C0,
        D_002832C8,
        D_002832D0,
        D_002832D8,
        D_002832E0,
        D_002832E8,
        D_002832F0,
        D_002832F8,
        D_00283300,
        D_00283308,
        D_00283310,
        D_00283318,
        D_00283320,
        D_00283328,
        D_00283330,
        D_00283338,
        D_00283340,
        D_00283348,
        D_00283350,
        D_00283358,
        D_00283360,
        D_00283368,
        D_00283370,
        D_00283378,
        D_00283380,
        D_00283388,
        D_00283390,
        D_00283398,
        D_002833A0,
        D_002833A8,
        death_D_002833B0,
        D_002833B8,
        D_002833C0,
        D_002833C8,
        D_002833D0,
        D_002833D8,
        D_002833E0,
        D_002833E8,
        D_002833F0,
        D_002833F8,
        D_00283400,
        D_00283408,
        D_00283410,
        D_00283418,
        D_00283420,
        D_00283428,
        D_00283430,
        D_00283438,
        D_00283440,
        D_00283448,
        D_00283450,
        D_00283458,
        D_00283460,
        D_00283468,
        D_00283470,
        D_00283478,
        D_00283480,
        D_00283488,
        D_00283490,
        D_00283498,
        D_002834A0,
        D_002834A8,
        D_002834B0,
        D_002834B8,
        D_002834C0,
        D_002834C8,
        D_002834D0,
        D_002834D8,
        D_002834E0,
        D_002834E8,
        D_002834F0,
        D_002834F8,
        D_00283500,
        D_00283508,
        D_00283510,
        D_00283518,
        D_00283520,
        D_00283528,
        D_00283530,
        D_00283538,
        D_00283540,
        D_00283548,
        D_00283550,
        D_00283558,
        D_00283560,
        D_00283568,
        D_00283570,
        D_00283578,
        D_00283580,
        D_00283588,
        D_00283590,
        D_00283598,
        D_002835A0,
        D_002835A8,
        D_002835B0,
        D_002835B8,
        D_002835C0,
        D_002835C8,
        D_002835D0,
        D_002835D8,
        D_002835E0,
        D_002835E8,
        D_002835F0,
        D_002835F8,
        D_00283600,
        D_00283608,
        D_00283610,
        D_00283618,
        D_00283620,
        D_00283628,
        D_00283630,
        D_00283638,
        D_00283640,
        D_00283648,
        D_00283650,
        D_00283658,
        D_00283660,
        D_00283668,
        D_00283670,
        D_00283678,
        D_00283680,
        D_00283688,
        D_00283690,
        D_00283698,
        D_002836A0,
        D_002836A8,
        D_002836B0,
        D_002836B8,
        D_002836C0,
        D_002836C8,
        D_002836D0,
        D_002836D8,
        D_002836E0,
        D_002836E8,
        D_002836F0,
        D_002836F8,
        D_00283700,
        D_00283708,
        D_00283710,
        D_00283718,
        D_00283720,
        D_00283728,
        D_00283730,
        D_00283738,
        D_00283740,
        D_00283748,
        D_00283750,
        D_00283758,
        D_00283760,
        D_00283768,
        D_00283770,
        D_00283778,
        D_00283780,
        D_00283788,
        D_00283790,
        D_00283798,
        D_002837A0,
        D_002837A8,
        D_002837B0,
        D_002837B8,
        D_002837C0,
        D_002837C8,
        D_002837D0,
        D_002837D8,
        D_002837E0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271290Record D_00271290 = {
    {
        D_0028FF98,
        D_0028FFA0,
        D_0028DCC8,
        &death_D_002623F0,
        (u8 *)&death_D_002623F0 + 32,
        D_0028FFB0,
        D_0028FFBC,
        (u8 *)&death_D_002623F0 + 80,
        D_0028FFB8,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_002712C0[12] = {
    0x0002, 0x0002, 0x0100, 0x0007, 0x0009, 0x0002, 0x0065, 0x0006,
    0x01F5, 0x0000, 0x0000, 0x0000,
};

s8 D_002712D8[14] = {
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, -1, -1, 0, 0,
};

struct D002712f0Record D_002712F0 = {
    {
        D_002837F0,
        D_00283810,
        D_00283820,
        D_00283830,
        D_00283840,
        D_00283850,
        D_00283860,
        D_00282310,
        D_00282080,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271320Record D_00271320 = {
    {
        D_00282088,
        D_00283870,
        D_002838A0,
        D_002838C0,
        D_002838F0,
        D_00283910,
        D_00283930,
        D_002823C0,
        D_00282140,
    },
    { 0x0000, 0x0000 },
    {
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        death_D_00282468,
        death_D_00282470,
        D_00282478,
        D_00282480,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
        death_D_00282458,
        death_D_00282460,
        death_D_00282468,
        death_D_00282470,
        D_00282478,
        D_00282480,
        D_00282488,
        D_00282490,
        D_00282498,
        D_002824A0,
        D_002824A8,
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        death_D_00282430,
        death_D_00282438,
        death_D_00282440,
        death_D_00282448,
        death_D_00282450,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_00282310,
        D_00282430,
        D_00282438,
        D_00282440,
        D_00282448,
        D_00282450,
        D_00282458,
        D_00282460,
        D_00282468,
        D_00282470,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271440[6] = {
    (u8 *)&D_00271320 + 40,
    (u8 *)&D_00271320 + 64,
    (u8 *)&D_00271320 + 112,
    (u8 *)&D_00271320 + 176,
    (u8 *)&D_00271320 + 208,
    (u8 *)&D_00271320 + 240,
};

u16 D_00271458[7] = {
    0x0003, 0x000A, 0x0010, 0x0005, 0x0005, 0x000A, 0x0000,
};

s8 D_00271468[14] = {
    -1, 0, 1, 2, 3, 4, 5, -1, -1, 0, 0, 0, 0, 0,
};

void *D_00271480[12] = {
    D_00282058,
    D_00283988,
    D_00283998,
    D_002839A8,
    D_002839B8,
    D_002839C8,
    D_002839D8,
    D_002839E8,
    D_002839F8,
    D_00283A08,
    D_00283A18,
    D_00282080,
};

struct D002714b0Record D_002714B0 = {
    {
        D_00283AC0,
        D_00283AE0,
        D_00283B00,
        D_00283B20,
        D_00283B40,
        D_00283B60,
        D_00283B80,
        D_00283BA0,
        D_00283BC0,
        D_00283B20,
        D_00283B40,
        D_00283B60,
        D_00283B80,
        D_00283BA0,
        D_00283BE0,
    },
    { 0x0000, 0x0000 },
};

s8 D_002714F0[32] = {
    6, 7, 5, 8, 0, 0, 0, 6, 6, 6, 12, 1, 12, 15, 6, 14,
    0, 8, 12, 9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
};

struct D00271510Record D_00271510 = {
    {
        D_00283C08,
        D_00283C18,
        D_00283C28,
        D_00283C30,
        D_00283C40,
        D_00282080,
        D_00283C50,
    },
    { 0x0000, 0x0000 },
};

struct D00271540Record D_00271540 = {
    {
        D_00283C60,
        D_00283C70,
        D_00283C80,
        D_00283C90,
        D_00283C98,
        D_00282310,
        D_00282080,
    },
    { 0x0000, 0x0000 },
};

struct D00271560Record D_00271560 = {
    {
        D_00283C40,
        D_00283CA8,
        D_00283CB0,
        D_00283CB8,
        D_00282080,
        D_00283CC8,
        D_00283CD0,
    },
    { 0x0000, 0x0000 },
};

void *D_00271580[8] = {
    D_00283C50,
    D_00283CE0,
    D_00283CF0,
    D_00283D00,
    D_00283D10,
    D_00283D20,
    D_00283D30,
    D_00282080,
};

struct D00271598Record D_00271598 = {
    {
        D_00283D40,
        D_00283D40,
        D_00283D50,
    },
    { 0x0000, 0x0000 },
};

struct D002715b0Record D_002715B0 = {
    {
        D_00283D60,
        D_00283C18,
        D_00283D70,
        D_00283C60,
        D_00283D80,
        D_00282080,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D002715d0Record D_002715D0 = {
    {
        D_00283C30,
        D_00283D90,
        D_00283DA0,
        D_00283DB0,
        D_00283DC0,
        D_00283DD0,
        D_00283DE0,
        D_00283DF0,
        D_00283E00,
        D_00283E20,
        D_00283E40,
        D_00283E60,
        D_00282310,
        D_00282080,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271610[12] = {
    D_00283AC0,
    D_00283E78,
    D_00283E80,
    D_00283E90,
    D_00283EB0,
    D_00283ED0,
    D_00283EF0,
    D_00283F10,
    D_00283E80,
    D_00283F30,
    D_00283E80,
    D_00283F50,
};

void *death_D_00262FF0[4] = {
    D_00283C60,
    D_00283F68,
    D_002822E0,
    D_00282080,
};

void *D_00271640[4] = {
    D_002823E0,
    D_002823E8,
    D_002823F0,
    D_002823F8,
};

struct D00271650Record D_00271650 = {
    {
        D_00282448,
        D_00282450,
        D_00282458,
        D_00282438,
        D_00282440,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271670[8] = {
    D_002824E0,
    D_002824F0,
    D_00282500,
    D_00282510,
    D_00282520,
    D_00282530,
    D_00282540,
    D_00282540,
};

s8 D_00271690[16] = {
    0, 2, 4, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s8 D_002716A0[16] = {
    0, 2, 2, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void *D_002716B0[4] = {
    D_00283F88,
    D_00283F78,
    D_00283F98,
    D_00283F80,
};

struct D002716c0Record D_002716C0 = {
    {
        D_00282438,
        D_00282440,
        D_00282448,
        D_00282450,
        D_00282458,
        D_00282800,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_002716E0[10] = {
    D_00283FD0,
    D_00283FD8,
    D_00283FE0,
    D_00283FE8,
    D_00283FF0,
    D_00283FF8,
    D_00284000,
    D_00284008,
    D_00284010,
    D_00284018,
};

void *death_D_002630C8[3] = {
    D_00282418,
    D_00282420,
    D_00282428,
};

struct D00271710Record D_00271710 = {
    {
        D_00284020,
        D_00283DA0,
        D_00283C98,
        D_00283DC0,
        D_00283DD0,
        D_00283DF0,
        D_00284028,
        D_00284030,
        D_00284038,
        D_00284048,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271740Record D_00271740 = {
    {
        D_00282438,
        D_00282440,
        D_00282448,
        D_00282450,
        D_00282458,
        D_00282800,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

s16 D_00271760[32] = {
    396, 8, 356, 8, 332, 8, 308, 8,
    284, 8, 260, 8, 236, 8, 212, 8,
    188, 8, 164, 8, 140, 8, 116, 8,
    92, 8, 68, 8, 20, 8, -4, 8,
};

u16 D_002717A0[32] = {
    0x01A4, 0x0008, 0x017C, 0x0008, 0x0164, 0x0008, 0x014C, 0x0008,
    0x0134, 0x0008, 0x011C, 0x0008, 0x0104, 0x0008, 0x00EC, 0x0008,
    0x00D4, 0x0008, 0x00BC, 0x0008, 0x00A4, 0x0008, 0x008C, 0x0008,
    0x0074, 0x0008, 0x005C, 0x0008, 0x002C, 0x0008, 0x0014, 0x0008,
};

s16 D_002717E0[16] = {
    382, 8, 311, 8, 240, 8, 169, 8,
    98, 8, 98, 8, 0, 0, 0, 0,
};

s16 D_00271800[136] = {
    0, 96, 96, 96, 96, 96, 96, 96,
    96, 96, 96, 96, 96, 96, 0, 0,
    0, 0, 1, 0, 3, 0, 6, 0,
    10, 0, 15, 0, 21, 0, 28, 0,
    36, 0, 45, 0, 55, 0, 66, 0,
    78, 0, 91, 0, 105, 0, 120, 0,
    136, 0, 153, 0, 171, 0, 190, 0,
    210, 0, 231, 0, 253, 0, 276, 0,
    300, 0, 325, 0, 351, 0, 378, 0,
    406, 0, 435, 0, 465, 0, 496, 0,
    528, 0, 561, 0, 595, 0, 630, 0,
    666, 0, 703, 0, 741, 0, 780, 0,
    820, 0, 861, 0, 903, 0, 946, 0,
    990, 0, 1035, 0, 1081, 0, 1128, 0,
    1176, 0, 1225, 0, 1275, 0, 1326, 0,
    1378, 0, 1431, 0, 1485, 0, 1540, 0,
    1596, 0, 1653, 0, 1711, 0, 1770, 0,
};

s32 D_00271910[64] = {
    1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278,
    2346, 2415, 2485, 2556, 2628, 2701, 2775, 2850,
    2926, 3003, 3081, 3160, 3240, 3321, 3403, 3486,
    3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186,
    4278, 4371, 4465, 4560, 4656, 4753, 4851, 4950,
    5050, 5151, 5253, 5356, 5460, 5565, 5671, 5778,
    5886, 5995, 6105, 6216, 6328, 6441, 6555, 6670,
    6786, 6903, 7021, 7140, 7260, 0, 0, 0,
};

u16 D_00271A10[8] = {
    0x2281, 0x2283, 0x2280, 0x2282, 0x227E, 0x227C, 0x227D, 0x227F,
};

struct D00271a20Record D_00271A20 = {
    {
        D_00282088,
        D_00284070,
        D_00284090,
        D_002840C0,
        D_002840F0,
        D_00284120,
        D_00284150,
    },
    { 0x0000, 0x0000 },
};

struct D00271a50Record D_00271A50 = {
    {
        D_00282088,
        D_00282320,
        D_00282380,
        D_002823A0,
        D_00284180,
        D_002841A0,
        D_00282140,
    },
    { 0x0000, 0x0000 },
};

struct D00271a70Record D_00271A70 = {
    {
        D_00282088,
        D_00284220,
        D_00284250,
        D_00284280,
        D_00282140,
        D_002842B0,
        D_002842D0,
    },
    { 0x0000, 0x0000 },
};

void *D_00271A90[8] = {
    D_00282088,
    D_002842F0,
    D_00284320,
    D_00284360,
    D_002843A0,
    D_002843C0,
    D_002843F0,
    D_00282140,
};

struct D00271ab0Record D_00271AB0 = {
    {
        D_00282088,
        D_00284070,
        D_00284430,
        D_00284460,
        D_00284490,
        D_00282140,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271ad0Record D_00271AD0 = {
    {
        D_00282088,
        D_002844C0,
        D_002844E0,
        D_00284510,
        D_00284540,
        D_00284570,
        D_002845A0,
        D_002845C0,
        D_00282088,
        D_00284610,
        D_00284640,
        D_00284670,
        D_002841A0,
        D_00282140,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *death_D_002634D0[4] = {
    D_00282088,
    D_00282340,
    D_00282360,
    D_00282140,
};

struct D00271b30Record D_00271B30 = {
    {
        D_00282088,
        D_002844E0,
        D_00284180,
        D_00284540,
        D_00284570,
        D_002845C0,
        D_002847B0,
        D_002847D0,
        D_002847F0,
        D_00284810,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271b90Record D_00271B90 = {
    {
        D_00282088,
        D_002844E0,
        D_00284180,
        D_00284540,
        D_00284570,
        D_002845C0,
        D_002847B0,
        D_00284860,
        D_002847F0,
        D_00284810,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_00284880,
        D_00284888,
    },
};

void *D_00271BC8[3] = {
    D_002848A0,
    D_002848C0,
    D_002848E0,
};

u8 D_00271BE0[128] = {
    0x95, 0xFB, 0x8C, 0xFC, 0x83, 0x4C, 0x81, 0x5B, 0x82, 0xCC, 0x81, 0xAA, 0x81, 0xAB, 0x81, 0xA9,
    0x81, 0xA8, 0x82, 0xC5, 0x81, 0x5E, 0x89, 0xE6, 0x96, 0xCA, 0x88, 0xCA, 0x92, 0x75, 0x82, 0xF0,
    0x92, 0xB2, 0x90, 0xAE, 0x82, 0xB5, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x5E, 0x81, 0x9B,
    0x83, 0x7B, 0x83, 0x5E, 0x83, 0x93, 0x82, 0xC5, 0x8C, 0x88, 0x92, 0xE8, 0x81, 0x41, 0x81, 0x7E,
    0x83, 0x7B, 0x83, 0x5E, 0x83, 0x93, 0x82, 0xC5, 0x81, 0x5E, 0x83, 0x4C, 0x83, 0x83, 0x83, 0x93,
    0x83, 0x5A, 0x83, 0x8B, 0x82, 0xC5, 0x82, 0xAB, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x5E,
    0x53, 0x45, 0x4C, 0x45, 0x43, 0x54, 0x82, 0xC5, 0x8F, 0x89, 0x8A, 0xFA, 0x92, 0x6C, 0x82, 0xC9,
    0x96, 0xDF, 0x82, 0xE8, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x8F, 0x00, 0x00, 0x00, 0x00,
};

struct D00271c60Record D_00271C60 = {
    { 0x14B5, 0x0000 },
    D_002620F0,
    { 0x14B6, 0x0000 },
    D_00262130,
    { 0x14B7, 0x0000 },
    D_00262170,
    { 0x14B8, 0x0000 },
    D_002621B0,
    { 0x14B9, 0x0000 },
    D_002621F0,
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_00271C90[8] = {
    0x0160, 0x005C, 0x0140, 0x000C, 0x0120, 0x000C, 0x0100, 0x000C,
};

u16 death_D_00263620[16] = {
    0x00E0, 0x000C, 0x00C0, 0x000C, 0x00A0, 0x000C, 0x0080, 0x000C,
    0x0060, 0x000C, 0x0040, 0x000C, 0x0020, 0x000C, 0x0000, 0x000C,
};

struct D00271cc0Record D_00271CC0 = {
    {
        D_00284AF8,
        D_00284028,
        D_00284030,
    },
    { 0x0000, 0x0000 },
};

struct D00271cd0Record D_00271CD0 = {
    {
        D_00282088,
        D_002847B0,
        D_00284B10,
    },
    { 0x0000, 0x0000 },
};

s16 D_00271CE0[16] = {
    396, 8, 356, 8, 332, 8, 308, 8,
    284, 8, 0, 0, 0, 0, 0, 0,
};

void *D_00271D00[4] = {
    D_00282838,
    D_00284C28,
    D_00284C30,
    D_00284C38,
};

void *D_00271D10[4] = {
    D_002823E0,
    D_002823E8,
    D_002823F0,
    D_00284C40,
};
#else
extern u8 D_002620F0[];
extern u8 D_00262130[];
extern u8 D_00262170[];
extern u8 D_002621B0[];
extern u8 D_002621F0[];
extern u8 D_002870C0[];
extern u8 D_002870D0[];
extern u8 D_002870D8[];
extern u8 D_002870E8[];
extern u8 D_002870F0[];
extern u8 D_00287100[];
extern u8 D_00287108[];
extern u8 D_00287110[];
extern u8 D_00287140[];
extern u8 D_00287170[];
extern u8 D_00287190[];
extern u8 D_002871C0[];
extern u8 D_002871E0[];
extern u8 D_00287200[];
extern u8 D_00287220[];
extern u8 D_00287238[];
extern u8 D_00287250[];
extern u8 D_00287280[];
extern u8 D_002872B0[];
extern u8 D_002872F0[];
extern u8 D_00287320[];
extern u8 D_00287330[];
extern u8 D_00287340[];
extern u8 D_00287350[];
extern u8 D_00287360[];
extern u8 D_00287370[];
extern u8 D_00287380[];
extern u8 D_00287390[];
extern u8 D_002873B0[];
extern u8 D_002873D0[];
extern u8 D_002873F0[];
extern u8 D_00287410[];
extern u8 D_00287430[];
extern u8 D_00287450[];
extern u8 D_00287458[];
extern u8 D_00287460[];
extern u8 D_00287468[];
extern u8 D_00287488[];
extern u8 D_00287490[];
extern u8 D_00287498[];
extern u8 D_002874A0[];
extern u8 D_002874A8[];
extern u8 D_002874B0[];
extern u8 D_002874B8[];
extern u8 D_002874C0[];
extern u8 D_002874C8[];
extern u8 D_002874D0[];
extern u8 D_002874D8[];
extern u8 D_002874E0[];
extern u8 D_002874E8[];
extern u8 D_002874F0[];
extern u8 D_002874F8[];
extern u8 D_00287500[];
extern u8 D_00287508[];
extern u8 D_00287510[];
extern u8 D_00287518[];
extern u8 D_00287520[];
extern u8 D_00287528[];
extern u8 D_00287530[];
extern u8 D_00287538[];
extern u8 D_00287540[];
extern u8 D_00287550[];
extern u8 D_00287560[];
extern u8 D_00287570[];
extern u8 D_00287580[];
extern u8 D_00287590[];
extern u8 D_002875A0[];
extern u8 D_002875B0[];
extern u8 D_002875C0[];
extern u8 D_002875D0[];
extern u8 D_002875E0[];
extern u8 D_002875F0[];
extern u8 D_00287600[];
extern u8 D_00287610[];
extern u8 D_00287620[];
extern u8 D_00287630[];
extern u8 D_00287640[];
extern u8 D_00287650[];
extern u8 D_00287680[];
extern u8 D_002876D0[];
extern u8 D_00287720[];
extern u8 D_00287750[];
extern u8 D_00287780[];
extern u8 D_002877C0[];
extern u8 D_002877F0[];
extern u8 D_00287840[];
extern u8 D_00287880[];
extern u8 D_002878B0[];
extern u8 D_002878B8[];
extern u8 D_002878C0[];
extern u8 D_002878C8[];
extern u8 D_002878D0[];
extern u8 D_002878D8[];
extern u8 D_002878E0[];
extern u8 D_002878E8[];
extern u8 D_002878F0[];
extern u8 D_002878F8[];
extern u8 D_00287900[];
extern u8 D_00287908[];
extern u8 D_00287910[];
extern u8 D_00287918[];
extern u8 D_00287920[];
extern u8 D_00287928[];
extern u8 D_00287930[];
extern u8 D_00287938[];
extern u8 D_00287940[];
extern u8 D_00287948[];
extern u8 D_00287950[];
extern u8 D_00287958[];
extern u8 D_00287960[];
extern u8 D_00287968[];
extern u8 D_00287970[];
extern u8 D_00287978[];
extern u8 D_00287980[];
extern u8 D_00287988[];
extern u8 D_00287990[];
extern u8 D_00287998[];
extern u8 D_002879A0[];
extern u8 D_002879A8[];
extern u8 D_002879B0[];
extern u8 D_002879B8[];
extern u8 D_002879C0[];
extern u8 D_002879C8[];
extern u8 D_002879D0[];
extern u8 D_002879D8[];
extern u8 D_002879E0[];
extern u8 D_002879E8[];
extern u8 D_002879F0[];
extern u8 D_002879F8[];
extern u8 D_00287A00[];
extern u8 D_00287A08[];
extern u8 D_00287A10[];
extern u8 D_00287A18[];
extern u8 D_00287A20[];
extern u8 D_00287A28[];
extern u8 D_00287A30[];
extern u8 D_00287A38[];
extern u8 D_00287A40[];
extern u8 D_00287A48[];
extern u8 D_00287A50[];
extern u8 D_00287A58[];
extern u8 D_00287A60[];
extern u8 D_00287A68[];
extern u8 D_00287A70[];
extern u8 D_00287A78[];
extern u8 D_00287A80[];
extern u8 D_00287A88[];
extern u8 D_00287A90[];
extern u8 D_00287A98[];
extern u8 D_00287AA0[];
extern u8 D_00287AA8[];
extern u8 D_00287AB0[];
extern u8 D_00287AB8[];
extern u8 D_00287AC0[];
extern u8 D_00287AC8[];
extern u8 D_00287AD0[];
extern u8 D_00287AD8[];
extern u8 D_00287AE0[];
extern u8 D_00287AE8[];
extern u8 D_00287AF0[];
extern u8 D_00287AF8[];
extern u8 D_00287B00[];
extern u8 D_00287B08[];
extern u8 D_00287B10[];
extern u8 D_00287B18[];
extern u8 D_00287B20[];
extern u8 D_00287B28[];
extern u8 D_00287B30[];
extern u8 D_00287B38[];
extern u8 D_00287B40[];
extern u8 D_00287B48[];
extern u8 D_00287B50[];
extern u8 D_00287B58[];
extern u8 D_00287B60[];
extern u8 D_00287B68[];
extern u8 D_00287B70[];
extern u8 D_00287B78[];
extern u8 D_00287B80[];
extern u8 D_00287B88[];
extern u8 D_00287B90[];
extern u8 D_00287B98[];
extern u8 D_00287BA0[];
extern u8 D_00287BA8[];
extern u8 D_00287BB0[];
extern u8 D_00287BB8[];
extern u8 D_00287BC0[];
extern u8 D_00287BC8[];
extern u8 D_00287BD0[];
extern u8 D_00287BD8[];
extern u8 D_00287BE0[];
extern u8 D_00287BE8[];
extern u8 D_00287BF0[];
extern u8 D_00287BF8[];
extern u8 D_00287C00[];
extern u8 D_00287C08[];
extern u8 D_00287C10[];
extern u8 D_00287C18[];
extern u8 D_00287C20[];
extern u8 D_00287C28[];
extern u8 D_00287C30[];
extern u8 D_00287C38[];
extern u8 D_00287C40[];
extern u8 D_00287C48[];
extern u8 D_00287C50[];
extern u8 D_00287C58[];
extern u8 D_00287C60[];
extern u8 D_00287C68[];
extern u8 D_00287C70[];
extern u8 D_00287C78[];
extern u8 D_00287C80[];
extern u8 D_00287C88[];
extern u8 D_00287C90[];
extern u8 D_00287C98[];
extern u8 D_00287CA0[];
extern u8 D_00287CA8[];
extern u8 D_00287CB0[];
extern u8 D_00287CB8[];
extern u8 D_00287CC0[];
extern u8 D_00287CC8[];
extern u8 D_00287CD0[];
extern u8 D_00287CD8[];
extern u8 D_00287CE0[];
extern u8 D_00287CE8[];
extern u8 D_00287CF0[];
extern u8 D_00287CF8[];
extern u8 D_00287D00[];
extern u8 D_00287D08[];
extern u8 D_00287D10[];
extern u8 D_00287D18[];
extern u8 D_00287D20[];
extern u8 D_00287D28[];
extern u8 D_00287D30[];
extern u8 D_00287D38[];
extern u8 D_00287D40[];
extern u8 D_00287D48[];
extern u8 D_00287D50[];
extern u8 D_00287D58[];
extern u8 D_00287D60[];
extern u8 D_00287D68[];
extern u8 D_00287D70[];
extern u8 D_00287D78[];
extern u8 D_00287D80[];
extern u8 D_00287D88[];
extern u8 D_00287D90[];
extern u8 D_00287D98[];
extern u8 D_00287DA0[];
extern u8 D_00287DA8[];
extern u8 D_00287DB0[];
extern u8 D_00287DB8[];
extern u8 D_00287DC0[];
extern u8 D_00287DC8[];
extern u8 D_00287DD0[];
extern u8 D_00287DD8[];
extern u8 D_00287DE0[];
extern u8 D_00287DE8[];
extern u8 D_00287DF0[];
extern u8 D_00287DF8[];
extern u8 D_00287E00[];
extern u8 D_00287E08[];
extern u8 D_00287E10[];
extern u8 D_00287E18[];
extern u8 D_00287E20[];
extern u8 D_00287E28[];
extern u8 D_00287E30[];
extern u8 D_00287E38[];
extern u8 D_00287E40[];
extern u8 D_00287E48[];
extern u8 D_00287E50[];
extern u8 D_00287E58[];
extern u8 D_00287E60[];
extern u8 D_00287E68[];
extern u8 D_00287E70[];
extern u8 D_00287E78[];
extern u8 D_00287E80[];
extern u8 D_00287E88[];
extern u8 D_00287E90[];
extern u8 D_00287E98[];
extern u8 D_00287EA0[];
extern u8 D_00287EA8[];
extern u8 D_00287EB0[];
extern u8 D_00287EB8[];
extern u8 D_00287EC0[];
extern u8 D_00287EC8[];
extern u8 D_00287ED0[];
extern u8 D_00287ED8[];
extern u8 D_00287EE0[];
extern u8 D_00287EE8[];
extern u8 D_00287EF0[];
extern u8 D_00287EF8[];
extern u8 D_00287F00[];
extern u8 D_00287F08[];
extern u8 D_00287F10[];
extern u8 D_00287F18[];
extern u8 D_00287F20[];
extern u8 D_00287F28[];
extern u8 D_00287F30[];
extern u8 D_00287F38[];
extern u8 D_00287F40[];
extern u8 D_00287F48[];
extern u8 D_00287F50[];
extern u8 D_00287F58[];
extern u8 D_00287F60[];
extern u8 D_00287F68[];
extern u8 D_00287F70[];
extern u8 D_00287F78[];
extern u8 D_00287F80[];
extern u8 D_00287F88[];
extern u8 D_00287F90[];
extern u8 D_00287F98[];
extern u8 D_00287FA0[];
extern u8 D_00287FA8[];
extern u8 D_00287FB0[];
extern u8 D_00287FB8[];
extern u8 D_00287FC0[];
extern u8 D_00287FC8[];
extern u8 D_00287FD0[];
extern u8 D_00287FD8[];
extern u8 D_00287FE0[];
extern u8 D_00287FE8[];
extern u8 D_00287FF0[];
extern u8 D_00287FF8[];
extern u8 D_00288000[];
extern u8 D_00288008[];
extern u8 D_00288010[];
extern u8 D_00288018[];
extern u8 D_00288020[];
extern u8 D_00288028[];
extern u8 D_00288030[];
extern u8 D_00288038[];
extern u8 D_00288040[];
extern u8 D_00288048[];
extern u8 D_00288050[];
extern u8 D_00288058[];
extern u8 D_00288060[];
extern u8 D_00288068[];
extern u8 D_00288070[];
extern u8 D_00288078[];
extern u8 D_00288080[];
extern u8 D_00288088[];
extern u8 D_00288090[];
extern u8 D_00288098[];
extern u8 D_002880A0[];
extern u8 D_002880A8[];
extern u8 D_002880B0[];
extern u8 D_002880B8[];
extern u8 D_002880C0[];
extern u8 D_002880C8[];
extern u8 D_002880D0[];
extern u8 D_002880D8[];
extern u8 D_002880E0[];
extern u8 D_002880E8[];
extern u8 D_002880F0[];
extern u8 D_002880F8[];
extern u8 D_00288100[];
extern u8 D_00288108[];
extern u8 D_00288110[];
extern u8 D_00288118[];
extern u8 D_00288120[];
extern u8 D_00288128[];
extern u8 D_00288130[];
extern u8 D_00288138[];
extern u8 D_00288140[];
extern u8 D_00288148[];
extern u8 D_00288150[];
extern u8 D_00288158[];
extern u8 D_00288160[];
extern u8 D_00288168[];
extern u8 D_00288170[];
extern u8 D_00288178[];
extern u8 D_00288180[];
extern u8 D_00288188[];
extern u8 D_00288190[];
extern u8 D_00288198[];
extern u8 D_002881A0[];
extern u8 D_002881A8[];
extern u8 D_002881B0[];
extern u8 D_002881B8[];
extern u8 D_002881C0[];
extern u8 D_002881C8[];
extern u8 D_002881D0[];
extern u8 D_002881D8[];
extern u8 D_002881E0[];
extern u8 D_002881E8[];
extern u8 D_002881F0[];
extern u8 D_002881F8[];
extern u8 D_00288200[];
extern u8 D_00288208[];
extern u8 D_00288210[];
extern u8 D_00288218[];
extern u8 D_00288220[];
extern u8 D_00288228[];
extern u8 D_00288230[];
extern u8 D_00288238[];
extern u8 D_00288240[];
extern u8 D_00288248[];
extern u8 D_00288250[];
extern u8 D_00288258[];
extern u8 D_00288260[];
extern u8 D_00288268[];
extern u8 D_00288270[];
extern u8 D_00288278[];
extern u8 D_00288280[];
extern u8 D_00288288[];
extern u8 D_00288290[];
extern u8 D_00288298[];
extern u8 D_002882A0[];
extern u8 D_002882A8[];
extern u8 D_002882B0[];
extern u8 D_002882B8[];
extern u8 D_002882C0[];
extern u8 D_002882C8[];
extern u8 D_002882D0[];
extern u8 D_002882D8[];
extern u8 D_002882E0[];
extern u8 D_002882E8[];
extern u8 D_002882F0[];
extern u8 D_002882F8[];
extern u8 D_00288300[];
extern u8 D_00288308[];
extern u8 D_00288310[];
extern u8 D_00288318[];
extern u8 D_00288320[];
extern u8 D_00288328[];
extern u8 D_00288330[];
extern u8 D_00288338[];
extern u8 D_00288340[];
extern u8 D_00288348[];
extern u8 D_00288350[];
extern u8 D_00288358[];
extern u8 D_00288360[];
extern u8 D_00288368[];
extern u8 D_00288370[];
extern u8 D_00288378[];
extern u8 D_00288380[];
extern u8 D_00288388[];
extern u8 D_00288390[];
extern u8 D_00288398[];
extern u8 D_002883A0[];
extern u8 D_002883A8[];
extern u8 D_002883B0[];
extern u8 D_002883B8[];
extern u8 D_002883C0[];
extern u8 D_002883C8[];
extern u8 D_002883D0[];
extern u8 D_002883D8[];
extern u8 D_002883E0[];
extern u8 D_002883E8[];
extern u8 D_002883F0[];
extern u8 D_002883F8[];
extern u8 D_00288400[];
extern u8 D_00288408[];
extern u8 D_00288410[];
extern u8 D_00288418[];
extern u8 D_00288420[];
extern u8 D_00288428[];
extern u8 D_00288430[];
extern u8 D_00288438[];
extern u8 D_00288440[];
extern u8 D_00288448[];
extern u8 D_00288450[];
extern u8 D_00288458[];
extern u8 D_00288460[];
extern u8 D_00288468[];
extern u8 D_00288470[];
extern u8 D_00288478[];
extern u8 D_00288480[];
extern u8 D_00288488[];
extern u8 D_00288490[];
extern u8 D_00288498[];
extern u8 D_002884A0[];
extern u8 D_002884A8[];
extern u8 D_002884B0[];
extern u8 D_002884B8[];
extern u8 D_002884C0[];
extern u8 D_002884C8[];
extern u8 D_002884D0[];
extern u8 D_002884D8[];
extern u8 D_002884E0[];
extern u8 D_002884E8[];
extern u8 D_002884F0[];
extern u8 D_002884F8[];
extern u8 D_00288500[];
extern u8 D_00288508[];
extern u8 D_00288510[];
extern u8 D_00288518[];
extern u8 D_00288520[];
extern u8 D_00288528[];
extern u8 D_00288530[];
extern u8 D_00288538[];
extern u8 D_00288540[];
extern u8 D_00288548[];
extern u8 D_00288550[];
extern u8 D_00288558[];
extern u8 D_00288560[];
extern u8 D_00288568[];
extern u8 D_00288570[];
extern u8 D_00288578[];
extern u8 D_00288580[];
extern u8 D_00288588[];
extern u8 D_00288590[];
extern u8 D_00288598[];
extern u8 D_002885A0[];
extern u8 D_002885A8[];
extern u8 D_002885B0[];
extern u8 D_002885B8[];
extern u8 D_002885C0[];
extern u8 D_002885C8[];
extern u8 D_002885D0[];
extern u8 D_002885D8[];
extern u8 D_002885E0[];
extern u8 D_002885E8[];
extern u8 D_002885F0[];
extern u8 D_002885F8[];
extern u8 D_00288600[];
extern u8 D_00288608[];
extern u8 D_00288610[];
extern u8 D_00288618[];
extern u8 D_00288620[];
extern u8 D_00288628[];
extern u8 D_00288630[];
extern u8 D_00288638[];
extern u8 D_00288640[];
extern u8 D_00288648[];
extern u8 D_00288650[];
extern u8 D_00288658[];
extern u8 D_00288660[];
extern u8 D_00288668[];
extern u8 D_00288670[];
extern u8 D_00288678[];
extern u8 D_00288680[];
extern u8 D_00288688[];
extern u8 D_00288690[];
extern u8 D_00288698[];
extern u8 D_002886A0[];
extern u8 D_002886A8[];
extern u8 D_002886B0[];
extern u8 D_002886B8[];
extern u8 D_002886C0[];
extern u8 D_002886C8[];
extern u8 D_002886D0[];
extern u8 D_002886D8[];
extern u8 D_002886E0[];
extern u8 D_002886E8[];
extern u8 D_002886F0[];
extern u8 D_002886F8[];
extern u8 D_00288700[];
extern u8 D_00288708[];
extern u8 D_00288710[];
extern u8 D_00288718[];
extern u8 D_00288720[];
extern u8 D_00288728[];
extern u8 D_00288730[];
extern u8 D_00288738[];
extern u8 D_00288740[];
extern u8 D_00288748[];
extern u8 D_00288750[];
extern u8 D_00288758[];
extern u8 D_00288760[];
extern u8 D_00288768[];
extern u8 D_00288770[];
extern u8 D_00288778[];
extern u8 D_00288780[];
extern u8 D_00288788[];
extern u8 D_00288790[];
extern u8 D_00288798[];
extern u8 D_002887A0[];
extern u8 D_002887A8[];
extern u8 D_002887B0[];
extern u8 D_002887B8[];
extern u8 D_002887C0[];
extern u8 D_002887C8[];
extern u8 D_002887D0[];
extern u8 D_002887D8[];
extern u8 D_002887E0[];
extern u8 D_002887E8[];
extern u8 D_002887F0[];
extern u8 D_002887F8[];
extern u8 D_00288800[];
extern u8 D_00288808[];
extern u8 D_00288810[];
extern u8 D_00288818[];
extern u8 D_00288820[];
extern u8 D_00288828[];
extern u8 D_00288830[];
extern u8 D_00288838[];
extern u8 D_00288840[];
extern u8 D_00288848[];
extern u8 D_00288850[];
extern u8 D_00288858[];
extern u8 D_00288860[];
extern u8 D_00288870[];
extern u8 D_00288890[];
extern u8 D_002888A0[];
extern u8 D_002888B0[];
extern u8 D_002888C0[];
extern u8 D_002888D0[];
extern u8 D_002888E0[];
extern u8 D_002888F0[];
extern u8 D_00288920[];
extern u8 D_00288940[];
extern u8 D_00288970[];
extern u8 D_00288990[];
extern u8 D_002889B0[];
extern u8 D_00288A18[];
extern u8 D_00288A28[];
extern u8 D_00288A38[];
extern u8 D_00288A48[];
extern u8 D_00288A58[];
extern u8 D_00288A68[];
extern u8 D_00288A78[];
extern u8 D_00288A88[];
extern u8 D_00288A98[];
extern u8 D_00288AA8[];
extern u8 D_00288B10[];
extern u8 D_00288B30[];
extern u8 D_00288B50[];
extern u8 D_00288B70[];
extern u8 D_00288B90[];
extern u8 D_00288BB0[];
extern u8 D_00288BD0[];
extern u8 D_00288BF0[];
extern u8 D_00288C10[];
extern u8 D_00288C30[];
extern u8 D_00288C58[];
extern u8 D_00288C60[];
extern u8 D_00288C70[];
extern u8 D_00288C80[];
extern u8 D_00288C88[];
extern u8 D_00288C90[];
extern u8 D_00288CA0[];
extern u8 D_00288CB0[];
extern u8 D_00288CC0[];
extern u8 D_00288CD0[];
extern u8 D_00288CE0[];
extern u8 D_00288CF0[];
extern u8 D_00288CF8[];
extern u8 D_00288D08[];
extern u8 D_00288D10[];
extern u8 D_00288D18[];
extern u8 D_00288D28[];
extern u8 D_00288D30[];
extern u8 D_00288D40[];
extern u8 D_00288D50[];
extern u8 D_00288D60[];
extern u8 D_00288D70[];
extern u8 D_00288D80[];
extern u8 D_00288D90[];
extern u8 D_00288DA0[];
extern u8 D_00288DB0[];
extern u8 D_00288DC0[];
extern u8 D_00288DD0[];
extern u8 D_00288DE0[];
extern u8 D_00288DF0[];
extern u8 D_00288E00[];
extern u8 D_00288E10[];
extern u8 D_00288E20[];
extern u8 D_00288E30[];
extern u8 D_00288E40[];
extern u8 D_00288E60[];
extern u8 D_00288E80[];
extern u8 D_00288EA0[];
extern u8 D_00288EB8[];
extern u8 D_00288EC0[];
extern u8 D_00288EE0[];
extern u8 D_00288F00[];
extern u8 D_00288F20[];
extern u8 D_00288F40[];
extern u8 D_00288F60[];
extern u8 D_00288F80[];
extern u8 D_00288F98[];
extern u8 D_00288FA0[];
extern u8 D_00288FA8[];
extern u8 D_00288FB8[];
extern u8 D_00288FF0[];
extern u8 D_00288FF8[];
extern u8 D_00289000[];
extern u8 D_00289008[];
extern u8 D_00289010[];
extern u8 D_00289018[];
extern u8 D_00289020[];
extern u8 D_00289028[];
extern u8 D_00289030[];
extern u8 D_00289038[];
extern u8 D_00289040[];
extern u8 D_00289048[];
extern u8 D_00289050[];
extern u8 D_00289058[];
extern u8 D_00289068[];
extern u8 D_00289090[];
extern u8 D_002890C0[];
extern u8 D_002890F0[];
extern u8 D_00289110[];
extern u8 D_00289130[];
extern u8 D_00289150[];
extern u8 D_00289180[];
extern u8 D_002891B0[];
extern u8 D_002891D0[];
extern u8 D_00289200[];
extern u8 D_00289220[];
extern u8 D_002892A0[];
extern u8 D_002892D0[];
extern u8 D_00289300[];
extern u8 D_00289330[];
extern u8 D_00289350[];
extern u8 D_00289370[];
extern u8 D_002893A0[];
extern u8 D_002893E0[];
extern u8 D_00289420[];
extern u8 D_00289460[];
extern u8 D_00289480[];
extern u8 D_002894B0[];
extern u8 D_002894E0[];
extern u8 D_00289510[];
extern u8 D_00289530[];
extern u8 D_00289560[];
extern u8 D_00289590[];
extern u8 D_002895C0[];
extern u8 D_002895F0[];
extern u8 D_00289610[];
extern u8 D_00289660[];
extern u8 D_00289690[];
extern u8 D_002896C0[];
extern u8 D_00289730[];
extern u8 D_00289750[];
extern u8 D_00289780[];
extern u8 D_00289800[];
extern u8 D_002898A0[];
extern u8 D_002898D0[];
extern u8 D_002898F0[];
extern u8 D_00289910[];
extern u8 D_00289930[];
extern u8 D_00289980[];
extern u8 D_002899A0[];
extern u8 D_002899C0[];
extern u8 D_002899C8[];
extern u8 D_002899E0[];
extern u8 D_00289A00[];
extern u8 D_00289A20[];
extern u8 D_00289A40[];
extern u8 D_00289C60[];
extern u8 D_00289C70[];
extern u8 D_00289CA0[];
extern u8 D_00289DB8[];
extern u8 D_00289DC0[];
extern u8 D_00289DC8[];
extern u8 D_00289DD0[];
extern u8 D_0028DCA0[];
extern u8 D_0028DCB8[];
extern u8 D_0028DCC0[];
extern u8 D_0028DCC8[];
extern u8 D_0028DCD0[];
extern u8 D_0028DCD8[];
extern u8 D_0028DCDC[];

extern s32 D_00270810[6];
extern u16 D_00270828[7];
extern u16 D_00270838[7];
struct D00270850Record { void *p0[6]; u16 w1[4]; };
extern struct D00270850Record D_00270850;
struct D00270870Record { void *p0[6]; u16 w1[4]; };
extern struct D00270870Record D_00270870;
struct D00270890Record { void *p0[6]; u16 w1[4]; };
extern struct D00270890Record D_00270890;
struct D002708b0Record { void *p0[6]; u16 w1[4]; };
extern struct D002708b0Record D_002708B0;
extern void *D_002708D0[8];
struct D002708f0Record { void *p0[15]; u16 w1[2]; };
extern struct D002708f0Record D_002708F0;
struct D00270930Record { void *p0[21]; u16 w1[6]; void *p2[8]; };
extern struct D00270930Record D_00270930;
struct D002709b0Record { void *p0[5]; u16 w1[6]; };
extern struct D002709b0Record D_002709B0;
extern void *D_002709D0[12];
struct D00270a00Record { void *p0[19]; u16 w1[2]; void *p2[9]; u16 w3[6]; void *p4[9]; u16 w5[6]; };
extern struct D00270a00Record D_00270A00;
struct D00270ab0Record { void *p0[501]; u16 w1[6]; };
extern struct D00270ab0Record D_00270AB0;
struct D00271290Record { void *p0[9]; u16 w1[6]; };
extern struct D00271290Record D_00271290;
extern u16 D_002712C0[12];
extern s8 D_002712D8[14];
struct D002712f0Record { void *p0[9]; u16 w1[6]; };
extern struct D002712f0Record D_002712F0;
struct D00271320Record { void *p0[9]; u16 w1[2]; void *p2[3]; u16 w3[6]; void *p4[10]; u16 w5[4]; void *p6[21]; u16 w7[6]; void *p8[5]; u16 w9[6]; void *p10[9]; u16 w11[6]; };
extern struct D00271320Record D_00271320;
extern void *D_00271440[6];
extern u16 D_00271458[7];
extern s8 D_00271468[14];
extern void *D_00271480[12];
struct D002714b0Record { void *p0[15]; u16 w1[2]; };
extern struct D002714b0Record D_002714B0;
extern s8 D_002714F0[32];
struct D00271510Record { void *p0[10]; u16 w1[4]; };
extern struct D00271510Record D_00271510;
struct D00271540Record { void *p0[7]; u16 w1[2]; };
extern struct D00271540Record D_00271540;
struct D00271560Record { void *p0[7]; u16 w1[2]; };
extern struct D00271560Record D_00271560;
extern void *D_00271580[6];
extern void *D_00271598[3];
struct D002715b0Record { void *p0[6]; u16 w1[4]; };
extern struct D002715b0Record D_002715B0;
struct D002715d0Record { void *p0[14]; u16 w1[4]; };
extern struct D002715d0Record D_002715D0;
extern void *D_00271610[12];
extern void *D_00271640[4];
struct D00271650Record { void *p0[5]; u16 w1[6]; };
extern struct D00271650Record D_00271650;
extern void *D_00271670[8];
extern s8 D_00271690[16];
extern s8 D_002716A0[16];
extern void *D_002716B0[4];
struct D002716c0Record { void *p0[6]; u16 w1[4]; };
extern struct D002716c0Record D_002716C0;
struct D002716e0Record { void *p0[10]; u16 w1[4]; };
extern struct D002716e0Record D_002716E0;
struct D00271710Record { void *p0[10]; u16 w1[4]; };
extern struct D00271710Record D_00271710;
struct D00271740Record { void *p0[6]; u16 w1[4]; };
extern struct D00271740Record D_00271740;
extern s16 D_00271760[32];
extern u16 D_002717A0[32];
extern s16 D_002717E0[16];
extern s16 D_00271800[136];
extern s32 D_00271910[64];
extern u16 D_00271A10[8];
struct D00271a20Record { void *p0[10]; u16 w1[4]; };
extern struct D00271a20Record D_00271A20;
struct D00271a50Record { void *p0[7]; u16 w1[2]; };
extern struct D00271a50Record D_00271A50;
struct D00271a70Record { void *p0[7]; u16 w1[2]; };
extern struct D00271a70Record D_00271A70;
struct D00271a90Record { void *p0[6]; u16 w1[4]; };
extern struct D00271a90Record D_00271A90;
struct D00271ab0Record { void *p0[6]; u16 w1[4]; };
extern struct D00271ab0Record D_00271AB0;
extern void *D_00271AD0[14];
extern void *D_00271B08[3];
extern void *D_00271B18[3];
struct D00271b30Record { void *p0[10]; u16 w1[4]; };
extern struct D00271b30Record D_00271B30;
struct D00271b60Record { void *p0[10]; u16 w1[4]; };
extern struct D00271b60Record D_00271B60;
struct D00271b90Record { void *p0[10]; u16 w1[4]; void *p2[4]; };
extern struct D00271b90Record D_00271B90;
struct D00271bd0Record { void *p0[2]; u16 w1[4]; };
extern struct D00271bd0Record D_00271BD0;
extern u8 D_00271BE0[128];
struct D00271c60Record { u16 w0[2]; void *p1; u16 w2[2]; void *p3; u16 w4[2]; void *p5; u16 w6[2]; void *p7; u16 w8[2]; void *p9; u16 w10[4]; };
extern struct D00271c60Record D_00271C60;
extern u16 D_00271C90[24];
struct D00271cc0Record { void *p0[3]; u16 w1[2]; };
extern struct D00271cc0Record D_00271CC0;
struct D00271cd0Record { void *p0[3]; u16 w1[2]; };
extern struct D00271cd0Record D_00271CD0;
extern s16 D_00271CE0[16];
extern void *D_00271D00[4];
extern void *D_00271D10[4];

s32 D_00270810[6] = {
    0, 393216, 8, 100, 0, 0,
};

u16 D_00270828[7] = {
    0x0001, 0x0000, 0x0000, 0x0014, 0x0000, 0x0000, 0x0000,
};

u16 D_00270838[7] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

struct D00270850Record D_00270850 = {
    {
        D_002870C0,
        D_002870D0,
        D_002870D8,
        D_002870E8,
        D_002870F0,
        D_00287100,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270870Record D_00270870 = {
    {
        D_00287108,
        D_00287110,
        D_00287140,
        D_00287170,
        D_00287190,
        D_002871C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270890Record D_00270890 = {
    {
        D_002870D0,
        D_002871E0,
        D_00287200,
        D_00287220,
        D_00287238,
        D_00287100,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D002708b0Record D_002708B0 = {
    {
        D_00287108,
        D_00287250,
        D_00287280,
        D_002872B0,
        D_002872F0,
        D_002871C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_002708D0[8] = {
    D_00287320,
    D_00287330,
    D_00287340,
    D_00287350,
    D_00287360,
    D_00287370,
    D_00287380,
    D_00287100,
};

struct D002708f0Record D_002708F0 = {
    {
        D_00287108,
        D_00287390,
        D_002873B0,
        D_002873D0,
        D_002873F0,
        D_00287410,
        D_00287430,
        D_002871C0,
        D_00287450,
        D_00287458,
        D_00287460,
        D_00287468,
        D_00287488,
        D_00287490,
        D_00287498,
    },
    { 0x0000, 0x0000 },
};

struct D00270930Record D_00270930 = {
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002874D8,
        D_002874E0,
        D_002874E8,
        D_002874F0,
        D_002874F8,
        D_00287500,
        D_00287508,
        D_00287510,
        D_00287518,
        D_00287520,
        D_00287528,
        D_00287530,
        D_00287538,
        D_00287540,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_00287550,
        D_00287560,
        D_00287570,
        D_00287580,
        D_00287590,
        D_002875A0,
        D_002875B0,
        D_002875B0,
    },
};

struct D002709b0Record D_002709B0 = {
    {
        (u8 *)&D_002708F0 + 32,
        D_0028DCA0,
        (u8 *)&D_002708F0 + 48,
        &D_00270930,
        (u8 *)&D_00270930 + 96,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_002709D0[12] = {
    D_00287200,
    D_002875C0,
    D_002875D0,
    D_002875E0,
    D_002875F0,
    D_00287600,
    D_00287610,
    D_00287620,
    D_00287630,
    D_00287640,
    D_00287380,
    D_00287100,
};

struct D00270a00Record D_00270A00 = {
    {
        D_00287108,
        D_00287650,
        D_00287680,
        D_002876D0,
        D_00287720,
        D_00287750,
        D_00287780,
        D_002877C0,
        D_002877F0,
        D_00287840,
        D_00287430,
        D_002871C0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_00287380,
    },
    { 0x0000, 0x0000 },
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002878B0,
        D_00287380,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002878B0,
        D_00287380,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00270ab0Record D_00270AB0 = {
    {
        D_002878C0,
        D_002878C8,
        D_002878D0,
        D_002878D8,
        D_002878E0,
        D_002878E8,
        D_002878F0,
        D_002878F8,
        D_00287900,
        D_00287908,
        D_00287910,
        D_00287918,
        D_00287920,
        D_00287928,
        D_00287930,
        D_00287938,
        D_00287940,
        D_00287948,
        D_00287950,
        D_00287958,
        D_00287960,
        D_00287968,
        D_00287970,
        D_00287978,
        D_00287980,
        D_00287988,
        D_00287990,
        D_00287998,
        D_002879A0,
        D_002879A8,
        D_002879B0,
        D_002879B8,
        D_002879C0,
        D_002879C8,
        D_002879D0,
        D_002879D8,
        D_002879E0,
        D_002879E8,
        D_002879F0,
        D_002879F8,
        D_00287A00,
        D_00287A08,
        D_00287A10,
        D_00287A18,
        D_00287A20,
        D_00287A28,
        D_00287A30,
        D_00287A38,
        D_00287A40,
        D_00287A48,
        D_00287A50,
        D_00287A58,
        D_00287A60,
        D_00287A68,
        D_00287A70,
        D_00287A78,
        D_00287A80,
        D_00287A88,
        D_00287A90,
        D_00287A98,
        D_00287AA0,
        D_00287AA8,
        D_00287AB0,
        D_00287AB8,
        D_00287AC0,
        D_00287AC8,
        D_00287AD0,
        D_00287AD8,
        D_00287AE0,
        D_00287AE8,
        D_00287AF0,
        D_00287AF8,
        D_00287B00,
        D_00287B08,
        D_00287B10,
        D_00287B18,
        D_00287B20,
        D_00287B28,
        D_00287B30,
        D_00287B38,
        D_00287B40,
        D_00287B48,
        D_00287B50,
        D_00287B58,
        D_00287B60,
        D_00287B68,
        D_00287B70,
        D_00287B78,
        D_00287B80,
        D_00287B88,
        D_00287B90,
        D_00287B98,
        D_00287BA0,
        D_00287BA8,
        D_00287BB0,
        D_00287BB8,
        D_00287BC0,
        D_00287BC8,
        D_00287BD0,
        D_00287BD8,
        D_00287BE0,
        D_00287BE8,
        D_00287BF0,
        D_00287BF8,
        D_00287C00,
        D_00287C08,
        D_00287C10,
        D_00287C18,
        D_00287C20,
        D_00287C28,
        D_00287C30,
        D_00287C38,
        D_00287C40,
        D_00287C48,
        D_00287C50,
        D_00287C58,
        D_00287C60,
        D_00287C68,
        D_00287C70,
        D_00287C78,
        D_00287C80,
        D_00287C88,
        D_00287C90,
        D_00287C98,
        D_00287CA0,
        D_00287CA8,
        D_00287CB0,
        D_00287CB8,
        D_00287CC0,
        D_00287CC8,
        D_00287CD0,
        D_00287CD8,
        D_00287CE0,
        D_00287CE8,
        D_00287CF0,
        D_00287CF8,
        D_00287D00,
        D_00287D08,
        D_00287D10,
        D_00287D18,
        D_00287D20,
        D_00287D28,
        D_00287D30,
        D_00287D38,
        D_00287D40,
        D_00287D48,
        D_00287D50,
        D_00287D58,
        D_00287D60,
        D_00287D68,
        D_00287D70,
        D_00287D78,
        D_00287D80,
        D_00287D88,
        D_00287D90,
        D_00287D98,
        D_00287DA0,
        D_00287DA8,
        D_00287DB0,
        D_00287DB8,
        D_00287DC0,
        D_00287DC8,
        D_00287DD0,
        D_00287DD8,
        D_00287DE0,
        D_00287DE8,
        D_00287DF0,
        D_00287DF8,
        D_00287E00,
        D_00287E08,
        D_00287E10,
        D_00287E18,
        D_00287E20,
        D_00287E28,
        D_00287E30,
        D_00287E38,
        D_00287E40,
        D_00287E48,
        D_00287E50,
        D_00287E58,
        D_00287E60,
        D_00287E68,
        D_00287E70,
        D_00287E78,
        D_00287E80,
        D_00287E88,
        D_00287E90,
        D_00287E98,
        D_00287EA0,
        D_00287EA8,
        D_00287EB0,
        D_00287EB8,
        D_00287EC0,
        D_00287EC8,
        D_00287ED0,
        D_00287ED8,
        D_00287EE0,
        D_00287EE8,
        D_00287EF0,
        D_00287EF8,
        D_00287F00,
        D_00287F08,
        D_00287F10,
        D_00287F18,
        D_00287F20,
        D_00287F28,
        D_00287F30,
        D_00287F38,
        D_00287F40,
        D_00287F48,
        D_00287F50,
        D_00287F58,
        D_00287F60,
        D_00287F68,
        D_00287F70,
        D_00287F78,
        D_00287F80,
        D_00287F88,
        D_00287F90,
        D_00287F98,
        D_00287FA0,
        D_00287FA8,
        D_00287FB0,
        D_00287FB8,
        D_00287FC0,
        D_00287FC8,
        D_00287FD0,
        D_00287FD8,
        D_00287FE0,
        D_00287FE8,
        D_00287FF0,
        D_00287FF8,
        D_00288000,
        D_00288008,
        D_00288010,
        D_00288018,
        D_00288020,
        D_00288028,
        D_00288030,
        D_00288038,
        D_00288040,
        D_00288048,
        D_00288050,
        D_00288058,
        D_00288060,
        D_00288068,
        D_00288070,
        D_00288078,
        D_00288080,
        D_00288088,
        D_00288090,
        D_00288098,
        D_002880A0,
        D_002880A8,
        D_002880B0,
        D_002880B8,
        D_002880C0,
        D_002880C8,
        D_002880D0,
        D_002880D8,
        D_002880E0,
        D_002880E8,
        D_002880F0,
        D_002880F8,
        D_00288100,
        D_00288108,
        D_00288110,
        D_00288118,
        D_00288120,
        D_00288128,
        D_00288130,
        D_00288138,
        D_00288140,
        D_00288148,
        D_00288150,
        D_00288158,
        D_00288160,
        D_00288168,
        D_00288170,
        D_00288178,
        D_00288180,
        D_00288188,
        D_00288190,
        D_00288198,
        D_002881A0,
        D_002881A8,
        D_002881B0,
        D_002881B8,
        D_002881C0,
        D_002881C8,
        D_002881D0,
        D_002881D8,
        D_002881E0,
        D_002881E8,
        D_002881F0,
        D_002881F8,
        D_00288200,
        D_00288208,
        D_00288210,
        D_00288218,
        D_00288220,
        D_00288228,
        D_00288230,
        D_00288238,
        D_00288240,
        D_00288248,
        D_00288250,
        D_00288258,
        D_00288260,
        D_00288268,
        D_00288270,
        D_00288278,
        D_00288280,
        D_00288288,
        D_00288290,
        D_00288298,
        D_002882A0,
        D_002882A8,
        D_002882B0,
        D_002882B8,
        D_002882C0,
        D_002882C8,
        D_002882D0,
        D_002882D8,
        D_002882E0,
        D_002882E8,
        D_002882F0,
        D_002882F8,
        D_00288300,
        D_00288308,
        D_00288310,
        D_00288318,
        D_00288320,
        D_00288328,
        D_00288330,
        D_00288338,
        D_00288340,
        D_00288348,
        D_00288350,
        D_00288358,
        D_00288360,
        D_00288368,
        D_00288370,
        D_00288378,
        D_00288380,
        D_00288388,
        D_00288390,
        D_00288398,
        D_002883A0,
        D_002883A8,
        D_002883B0,
        D_002883B8,
        D_002883C0,
        D_002883C8,
        D_002883D0,
        D_002883D8,
        D_002883E0,
        D_002883E8,
        D_002883F0,
        D_002883F8,
        D_00288400,
        D_00288408,
        D_00288410,
        D_00288418,
        D_00288420,
        D_00288428,
        D_00288430,
        D_00288438,
        D_00288440,
        D_00288448,
        D_00288450,
        D_00288458,
        D_00288460,
        D_00288468,
        D_00288470,
        D_00288478,
        D_00288480,
        D_00288488,
        D_00288490,
        D_00288498,
        D_002884A0,
        D_002884A8,
        D_002884B0,
        D_002884B8,
        D_002884C0,
        D_002884C8,
        D_002884D0,
        D_002884D8,
        D_002884E0,
        D_002884E8,
        D_002884F0,
        D_002884F8,
        D_00288500,
        D_00288508,
        D_00288510,
        D_00288518,
        D_00288520,
        D_00288528,
        D_00288530,
        D_00288538,
        D_00288540,
        D_00288548,
        D_00288550,
        D_00288558,
        D_00288560,
        D_00288568,
        D_00288570,
        D_00288578,
        D_00288580,
        D_00288588,
        D_00288590,
        D_00288598,
        D_002885A0,
        D_002885A8,
        D_002885B0,
        D_002885B8,
        D_002885C0,
        D_002885C8,
        D_002885D0,
        D_002885D8,
        D_002885E0,
        D_002885E8,
        D_002885F0,
        D_002885F8,
        D_00288600,
        D_00288608,
        D_00288610,
        D_00288618,
        D_00288620,
        D_00288628,
        D_00288630,
        D_00288638,
        D_00288640,
        D_00288648,
        D_00288650,
        D_00288658,
        D_00288660,
        D_00288668,
        D_00288670,
        D_00288678,
        D_00288680,
        D_00288688,
        D_00288690,
        D_00288698,
        D_002886A0,
        D_002886A8,
        D_002886B0,
        D_002886B8,
        D_002886C0,
        D_002886C8,
        D_002886D0,
        D_002886D8,
        D_002886E0,
        D_002886E8,
        D_002886F0,
        D_002886F8,
        D_00288700,
        D_00288708,
        D_00288710,
        D_00288718,
        D_00288720,
        D_00288728,
        D_00288730,
        D_00288738,
        D_00288740,
        D_00288748,
        D_00288750,
        D_00288758,
        D_00288760,
        D_00288768,
        D_00288770,
        D_00288778,
        D_00288780,
        D_00288788,
        D_00288790,
        D_00288798,
        D_002887A0,
        D_002887A8,
        D_002887B0,
        D_002887B8,
        D_002887C0,
        D_002887C8,
        D_002887D0,
        D_002887D8,
        D_002887E0,
        D_002887E8,
        D_002887F0,
        D_002887F8,
        D_00288800,
        D_00288808,
        D_00288810,
        D_00288818,
        D_00288820,
        D_00288828,
        D_00288830,
        D_00288838,
        D_00288840,
        D_00288848,
        D_00288850,
        D_00288858,
        D_00288860,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271290Record D_00271290 = {
    {
        D_0028DCB8,
        D_0028DCC0,
        D_0028DCC8,
        (u8 *)&D_00270A00 + 48,
        (u8 *)&D_00270A00 + 80,
        D_0028DCD0,
        D_0028DCDC,
        (u8 *)&D_00270A00 + 128,
        D_0028DCD8,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_002712C0[12] = {
    0x0002, 0x0002, 0x0100, 0x0007, 0x0009, 0x0002, 0x0065, 0x0006,
    0x01F5, 0x0000, 0x0000, 0x0000,
};

s8 D_002712D8[14] = {
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, -1, -1, 0, 0,
};

struct D002712f0Record D_002712F0 = {
    {
        D_00288870,
        D_00288890,
        D_002888A0,
        D_002888B0,
        D_002888C0,
        D_002888D0,
        D_002888E0,
        D_00287380,
        D_00287100,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271320Record D_00271320 = {
    {
        D_00287108,
        D_002888F0,
        D_00288920,
        D_00288940,
        D_00288970,
        D_00288990,
        D_002889B0,
        D_00287430,
        D_002871C0,
    },
    { 0x0000, 0x0000 },
    {
        D_002874A8,
        D_002874B0,
        D_002874B8,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002874D8,
        D_002874E0,
        D_002874E8,
        D_002874F0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002874D8,
        D_002874E0,
        D_002874E8,
        D_002874F0,
        D_002874F8,
        D_00287500,
        D_00287508,
        D_00287510,
        D_00287518,
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002874A0,
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874D0,
        D_002874D8,
        D_002874E0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271440[6] = {
    (u8 *)&D_00271320 + 40,
    (u8 *)&D_00271320 + 64,
    (u8 *)&D_00271320 + 112,
    (u8 *)&D_00271320 + 176,
    (u8 *)&D_00271320 + 208,
    (u8 *)&D_00271320 + 240,
};

u16 D_00271458[7] = {
    0x0003, 0x000A, 0x0010, 0x0005, 0x0005, 0x0009, 0x0000,
};

s8 D_00271468[14] = {
    -1, 0, 1, 2, 3, 4, 5, -1, -1, 0, 0, 0, 0, 0,
};

void *D_00271480[12] = {
    D_002870D8,
    D_00288A18,
    D_00288A28,
    D_00288A38,
    D_00288A48,
    D_00288A58,
    D_00288A68,
    D_00288A78,
    D_00288A88,
    D_00288A98,
    D_00288AA8,
    D_00287100,
};

struct D002714b0Record D_002714B0 = {
    {
        D_00288B10,
        D_00288B30,
        D_00288B50,
        D_00288B70,
        D_00288B90,
        D_00288BB0,
        D_00288BD0,
        D_00288BF0,
        D_00288C10,
        D_00288B70,
        D_00288B90,
        D_00288BB0,
        D_00288BD0,
        D_00288BF0,
        D_00288C30,
    },
    { 0x0000, 0x0000 },
};

s8 D_002714F0[32] = {
    9, 7, 5, 6, 0, 0, 0, 6, 6, 6, 12, 1, 12, 15, 6, 14,
    0, 8, 12, 9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0,
};

struct D00271510Record D_00271510 = {
    {
        D_00288C58,
        D_00288C60,
        D_002870C0,
        D_00288C70,
        D_00288C80,
        D_00288C88,
        D_00288C90,
        D_00288CA0,
        D_00287100,
        D_00288CB0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271540Record D_00271540 = {
    {
        D_00288CC0,
        D_00288CD0,
        D_00288CE0,
        D_00288CF0,
        D_00288CF8,
        D_00287380,
        D_00287100,
    },
    { 0x0000, 0x0000 },
};

struct D00271560Record D_00271560 = {
    {
        D_00288CA0,
        D_00288D08,
        D_00288D10,
        D_00288D18,
        D_00287100,
        D_00288D28,
        D_00288D30,
    },
    { 0x0000, 0x0000 },
};

void *D_00271580[6] = {
    D_00288CB0,
    D_00288D40,
    D_00288D50,
    D_00288D60,
    D_00288D70,
    D_00287100,
};

void *D_00271598[3] = {
    D_00288D80,
    D_00288D80,
    D_00288D90,
};

struct D002715b0Record D_002715B0 = {
    {
        D_00288C60,
        D_00288DA0,
        D_00288DB0,
        D_00288CC0,
        D_00288DC0,
        D_00287100,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D002715d0Record D_002715D0 = {
    {
        D_00288C90,
        D_00288DD0,
        D_00288DE0,
        D_00288DF0,
        D_00288E00,
        D_00288E10,
        D_00288E20,
        D_00288E30,
        D_00288E40,
        D_00288E60,
        D_00288E80,
        D_00288EA0,
        D_00287380,
        D_00287100,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271610[12] = {
    D_00288B10,
    D_00288EB8,
    D_00288C58,
    D_00288EC0,
    D_00288EE0,
    D_00288F00,
    D_00288F20,
    D_00288F40,
    D_00288C58,
    D_00288F60,
    D_00288C58,
    D_00288F80,
};

void *D_00271640[4] = {
    D_00287450,
    D_00287458,
    D_00287460,
    D_00287468,
};

struct D00271650Record D_00271650 = {
    {
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_002874A8,
        D_002874B0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271670[8] = {
    D_00287550,
    D_00287560,
    D_00287570,
    D_00287580,
    D_00287590,
    D_002875A0,
    D_002875B0,
    D_002875B0,
};

s8 D_00271690[16] = {
    0, 2, 4, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

s8 D_002716A0[16] = {
    0, 2, 2, 2, 6, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void *D_002716B0[4] = {
    D_00288FA8,
    D_00288F98,
    D_00288FB8,
    D_00288FA0,
};

struct D002716c0Record D_002716C0 = {
    {
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_00287880,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D002716e0Record D_002716E0 = {
    {
        D_00288FF0,
        D_00288FF8,
        D_00289000,
        D_00289008,
        D_00289010,
        D_00289018,
        D_00289020,
        D_00289028,
        D_00289030,
        D_00289038,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271710Record D_00271710 = {
    {
        D_00289040,
        D_00288DE0,
        D_00288CF8,
        D_00288E00,
        D_00288E10,
        D_00288E30,
        D_00289048,
        D_00289050,
        D_00289058,
        D_00289068,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271740Record D_00271740 = {
    {
        D_002874A8,
        D_002874B0,
        D_002874B8,
        D_002874C0,
        D_002874C8,
        D_00287880,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

s16 D_00271760[32] = {
    396, 8, 356, 8, 332, 8, 308, 8,
    284, 8, 260, 8, 236, 8, 212, 8,
    188, 8, 164, 8, 140, 8, 116, 8,
    92, 8, 68, 8, 20, 8, -4, 8,
};

u16 D_002717A0[32] = {
    0x01A4, 0x0008, 0x017C, 0x0008, 0x0164, 0x0008, 0x014C, 0x0008,
    0x0134, 0x0008, 0x011C, 0x0008, 0x0104, 0x0008, 0x00EC, 0x0008,
    0x00D4, 0x0008, 0x00BC, 0x0008, 0x00A4, 0x0008, 0x008C, 0x0008,
    0x0074, 0x0008, 0x005C, 0x0008, 0x002C, 0x0008, 0x0014, 0x0008,
};

s16 D_002717E0[16] = {
    382, 8, 311, 8, 240, 8, 169, 8,
    98, 8, 98, 8, 0, 0, 0, 0,
};

s16 D_00271800[136] = {
    0, 96, 96, 96, 96, 96, 96, 96,
    96, 96, 96, 96, 96, 96, 0, 0,
    0, 0, 1, 0, 3, 0, 6, 0,
    10, 0, 15, 0, 21, 0, 28, 0,
    36, 0, 45, 0, 55, 0, 66, 0,
    78, 0, 91, 0, 105, 0, 120, 0,
    136, 0, 153, 0, 171, 0, 190, 0,
    210, 0, 231, 0, 253, 0, 276, 0,
    300, 0, 325, 0, 351, 0, 378, 0,
    406, 0, 435, 0, 465, 0, 496, 0,
    528, 0, 561, 0, 595, 0, 630, 0,
    666, 0, 703, 0, 741, 0, 780, 0,
    820, 0, 861, 0, 903, 0, 946, 0,
    990, 0, 1035, 0, 1081, 0, 1128, 0,
    1176, 0, 1225, 0, 1275, 0, 1326, 0,
    1378, 0, 1431, 0, 1485, 0, 1540, 0,
    1596, 0, 1653, 0, 1711, 0, 1770, 0,
};

s32 D_00271910[64] = {
    1830, 1891, 1953, 2016, 2080, 2145, 2211, 2278,
    2346, 2415, 2485, 2556, 2628, 2701, 2775, 2850,
    2926, 3003, 3081, 3160, 3240, 3321, 3403, 3486,
    3570, 3655, 3741, 3828, 3916, 4005, 4095, 4186,
    4278, 4371, 4465, 4560, 4656, 4753, 4851, 4950,
    5050, 5151, 5253, 5356, 5460, 5565, 5671, 5778,
    5886, 5995, 6105, 6216, 6328, 6441, 6555, 6670,
    6786, 6903, 7021, 7140, 7260, 0, 0, 0,
};

u16 D_00271A10[8] = {
    0x2281, 0x2283, 0x2280, 0x2282, 0x227E, 0x227C, 0x227D, 0x227F,
};

struct D00271a20Record D_00271A20 = {
    {
        D_00287108,
        D_00289090,
        D_002890C0,
        D_002890F0,
        D_00289110,
        D_00289130,
        D_00289150,
        D_00289180,
        D_002891B0,
        D_002891D0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271a50Record D_00271A50 = {
    {
        D_00287108,
        D_00287390,
        D_002873F0,
        D_00287410,
        D_00289200,
        D_00289220,
        D_002871C0,
    },
    { 0x0000, 0x0000 },
};

struct D00271a70Record D_00271A70 = {
    {
        D_00287108,
        D_002892A0,
        D_002892D0,
        D_00289300,
        D_002871C0,
        D_00289330,
        D_00289350,
    },
    { 0x0000, 0x0000 },
};

struct D00271a90Record D_00271A90 = {
    {
        D_00287108,
        D_00289370,
        D_002893A0,
        D_002893E0,
        D_00289420,
        D_002871C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271ab0Record D_00271AB0 = {
    {
        D_00287108,
        D_00289460,
        D_00289480,
        D_002894B0,
        D_002894E0,
        D_002871C0,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

void *D_00271AD0[14] = {
    D_00287108,
    D_00289510,
    D_00289530,
    D_00289560,
    D_00289590,
    D_002895C0,
    D_002895F0,
    D_00289610,
    D_00287108,
    D_00289660,
    D_00289690,
    D_002896C0,
    D_00289220,
    D_002871C0,
};

void *D_00271B08[3] = {
    D_00287108,
    D_00289730,
    D_00289750,
};

void *D_00271B18[3] = {
    D_00287108,
    D_00289780,
    D_00289800,
};

struct D00271b30Record D_00271B30 = {
    {
        D_00287108,
        D_00289530,
        D_00289200,
        D_00289590,
        D_002898A0,
        D_00289610,
        D_002898D0,
        D_002898F0,
        D_00289910,
        D_00289930,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271b60Record D_00271B60 = {
    {
        D_00287108,
        D_00289530,
        D_00289200,
        D_00289590,
        D_002898A0,
        D_00289610,
        D_002898D0,
        D_00289980,
        D_00289910,
        D_00289930,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct D00271b90Record D_00271B90 = {
    {
        D_00287108,
        D_00289530,
        D_00289200,
        D_00289590,
        D_002898A0,
        D_00289610,
        D_002898D0,
        D_002899A0,
        D_00289910,
        D_00289930,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    {
        D_002899C0,
        D_002899C8,
        D_002899E0,
        D_00289A00,
    },
};

struct D00271bd0Record D_00271BD0 = {
    {
        D_00289A20,
        D_00289A40,
    },
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

u8 D_00271BE0[128] = {
    0x95, 0xFB, 0x8C, 0xFC, 0x83, 0x4C, 0x81, 0x5B, 0x82, 0xCC, 0x81, 0xAA, 0x81, 0xAB, 0x81, 0xA9,
    0x81, 0xA8, 0x82, 0xC5, 0x81, 0x5E, 0x89, 0xE6, 0x96, 0xCA, 0x88, 0xCA, 0x92, 0x75, 0x82, 0xF0,
    0x92, 0xB2, 0x90, 0xAE, 0x82, 0xB5, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x5E, 0x81, 0x9B,
    0x83, 0x7B, 0x83, 0x5E, 0x83, 0x93, 0x82, 0xC5, 0x8C, 0x88, 0x92, 0xE8, 0x81, 0x41, 0x81, 0x7E,
    0x83, 0x7B, 0x83, 0x5E, 0x83, 0x93, 0x82, 0xC5, 0x81, 0x5E, 0x83, 0x4C, 0x83, 0x83, 0x83, 0x93,
    0x83, 0x5A, 0x83, 0x8B, 0x82, 0xC5, 0x82, 0xAB, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x5E,
    0x53, 0x45, 0x4C, 0x45, 0x43, 0x54, 0x82, 0xC5, 0x8F, 0x89, 0x8A, 0xFA, 0x92, 0x6C, 0x82, 0xC9,
    0x96, 0xDF, 0x82, 0xE8, 0x82, 0xDC, 0x82, 0xB7, 0x81, 0x42, 0x81, 0x8F, 0x00, 0x00, 0x00, 0x00,
};

struct D00271c60Record D_00271C60 = {
    { 0x14B5, 0x0000 },
    D_002620F0,
    { 0x14B6, 0x0000 },
    D_00262130,
    { 0x14B7, 0x0000 },
    D_00262170,
    { 0x14B8, 0x0000 },
    D_002621B0,
    { 0x14B9, 0x0000 },
    D_002621F0,
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_00271C90[24] = {
    0x0160, 0x005C, 0x0140, 0x000C, 0x0120, 0x000C, 0x0100, 0x000C,
    0x00E0, 0x000C, 0x00C0, 0x000C, 0x00A0, 0x000C, 0x0080, 0x000C,
    0x0060, 0x000C, 0x0040, 0x000C, 0x0020, 0x000C, 0x0000, 0x000C,
};

struct D00271cc0Record D_00271CC0 = {
    {
        D_00289C60,
        D_00289048,
        D_00289050,
    },
    { 0x0000, 0x0000 },
};

struct D00271cd0Record D_00271CD0 = {
    {
        D_00287108,
        D_00289C70,
        D_00289CA0,
    },
    { 0x0000, 0x0000 },
};

s16 D_00271CE0[16] = {
    396, 8, 356, 8, 332, 8, 308, 8,
    284, 8, 0, 0, 0, 0, 0, 0,
};

void *D_00271D00[4] = {
    D_002878B8,
    D_00289DB8,
    D_00289DC0,
    D_00289DC8,
};

void *D_00271D10[4] = {
    D_00287450,
    D_00287458,
    D_00287460,
    D_00289DD0,
};
#endif
