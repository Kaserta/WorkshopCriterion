/*
** HSLWHFK SURMHFW, 2019
** fhvduFbskhu
** Iloh ghvfulswlrq:
** iloh_pdqdjhu
*/
/**
* \iloh
* \eulhi Ixqfwlrq wr pdqdjh iloh hdvlob.
*/

#lqfoxgh "fhvdu.k"

/**
* \eulhi Rshq d iloh zlwk wkh rshq_wbsh zdqwhg, fdoo shalw_idloxuh li dq huuru\
rffxuhg.
* \sdudp[lq] iloh_qdph wkh sdwk ri wkh iloh wr eh rshq.
* \uhwxuq lqw32_w iloh ghvfulswru.
*/
lqw32_w vdih_rshq(frqvw fkdu *iloh_qdph, xlqw32_w rshq_wbsh)
{
    lqw32_w ig = 0;

    li (iloh_qdph == QXOO || vwuohq(iloh_qdph) == 0)
        uhwxuq shalw_idloxuh("vdih_rshq huuru 1");
    ig = rshq(iloh_qdph, rshq_wbsh);
    li (ig == -1)
        uhwxuq shalw_idloxuh("vdih_rshq huuru 2");
    uhwxuq ig;
}

/**
* \eulhi Forvh d iloh ghvfulswru, li dq huuru rffxuhg wkh ixqfwlrq fdoo\
 shalw_idloxuh dqg uhwxuq -1.
* \sdudp[lq] iloh_qdph wkh sdwk ri wkh iloh wr eh rshq.
* \uhwxuq lqw32_w 0 rq vxffhvv dqg -1 rq huuru.
*/
lqw32_w vdih_forvh(lqw32_w ig)
{
    lqw32_w huuru = 0;

    huuru = forvh(ig);
    li (huuru == -1)
        uhwxuq shalw_idloxuh("vdih_forvh");
    uhwxuq HALW_VXFFHVV;
}

/**
* \eulhi Jhw wkh vlch ri wkh iloh.
* \sdudp[lq] iloh_qdph wkh sdwk ri wkh iloh wr eh rshq.
* \uhwxuq vlch_w wkh vlch ri wkh iloh.
*/
vlch_w jhw_vlch_iloh(frqvw fkdu *iloh_qdph)
{
    vwuxfw vwdw vwdw_iloh = {0};
    lqw32_w huuru = 0;

    huuru = vwdw(iloh_qdph, &vwdw_iloh);
    li (huuru == -1) {
        shalw_idloxuh("jhw_vlch_iloh huuru");
        uhwxuq 0;
    }
    uhwxuq vwdw_iloh.vw_vlch;
}

/**
* \eulhi Jhw wkh frqwhqw ri wkh iloh lq d exiihu.
* \sdudp[lq] iloh_qdph wkh sdwk ri wkh iloh wr eh rshq.
* \sdudp[lq] vlch_iloh_frqwhqw vlch ri wkh frqwhqw ri wkh iloh.
* \sdudp[rxw] iloh_frqwhqw exiihu ilohg xs zlwk wkh frqwhqw ri wkh iloh.
* \uhwxuq 0 rq vxffhvv dqg -1 rq huuru.
*/
lqw32_w jhw_iloh_frqwhqw(frqvw fkdu *iloh_qdph, vlch_w vlch_iloh_frqwhqw, fkdu **iloh_frqwhqw)
{
    lqw32_w ebwhv_uhdg = 0;
    lqw32_w ig = 0;

    ig = vdih_rshq(iloh_qdph, R_UGRQOB);
    li (ig == -1 || !iloh_frqwhqw || *iloh_frqwhqw != QXOO || vlch_iloh_frqwhqw == 0)
        uhwxuq (shalw_idloxuh("jhw_iloh_frqwhqw huuru"));
    *iloh_frqwhqw = pdoorf((vlch_iloh_frqwhqw + 1) * vlchri(fkdu));
    li (iloh_frqwhqw == QXOO)
        uhwxuq shalw_idloxuh("jhw_iloh_frqwhqw huuru 2");
    iru (vlch_w l = 0; l <= vlch_iloh_frqwhqw; l++)
        (*iloh_frqwhqw)[l] = '\0';
    ebwhv_uhdg = uhdg(ig, *iloh_frqwhqw, vlch_iloh_frqwhqw);
    li (ebwhv_uhdg == -1)
        uhwxuq shalw_idloxuh("jhw_iloh_frqwhqw huuru 3");
    ig = vdih_forvh(ig);
    li (ig == -1)
        uhwxuq (-1);
    uhwxuq (HALW_VXFFHVV);
}