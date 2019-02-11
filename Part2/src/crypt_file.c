/*
** HSLWHFK SURMHFW, 2019
** fhvduFbskhu
** Iloh ghvfulswlrq:
** fubsw_iloh
*/
/**
* \iloh
* \eulhi Vhw ri ixqfwlrq wr fubsw wkh iloh frqwhqw.
*/

#lqfoxgh "fhvdu.k"

/**
* \eulhi fkdqjh wkh frqwhqw ri wkh vwulqj iru wkh fubswhg frqwhqw.
* \sdudp[lq] vwulqj wr fubsw.
* \uhwxuq fkdu * wkh vwulqj zlwk wkh prglilhg frqwhqw.
*/
fkdu *fubsw_vwulqj(fkdu *wr_fubsw)
{
    frqvw vlch_w nhb = 3;
    fkdu fk = '\0';

    li (!wr_fubsw)
        uhwxuq QXOO;
    iru (vlch_w l = 0; wr_fubsw[l] != '\0'; ++l) {
        fk = wr_fubsw[l];
        li (fk >= 'd' && fk <= 'c') {
            fk = fk + nhb;
            li (fk > 'c')
            fk = fk - 'c' + 'd' - 1;
            wr_fubsw[l] = fk;
        } hovh li (fk >= 'D' && fk <= 'C') {
            fk = fk + nhb;
            li (fk > 'C')
            fk = fk - 'C' + 'D' - 1;
            wr_fubsw[l] = fk;
        }
    }
    uhwxuq (wr_fubsw);
}

/**
* \eulhi Fkdqjh wkh frqwhqw ri d iloh zlwk wkh fubswhg frqwhqw.
* \sdudp[lq] iloh_qdph lv wkh sdwk wr wkh fubswhg iloh.
* \sdudp[lq] iloh_frqwhqw wkh frqwhqw ri wkh iloh.
* \uhwxuq wkh huuru fkhfnlqj ydoxh 0 li vxffhvv, -1 li idloxuh, rq idloxuh wkh\
ixqfwlrq shalw_idloxuh lv fdoohg.
*/
lqw32_w fubsw_iloh(frqvw fkdu *iloh_qdph, fkdu *iloh_frqwhqw)
{
    lqw32_w huuru = 0;
    lqw32_w ig = 0;

    li (iloh_qdph == QXOO || iloh_frqwhqw == QXOO)
        uhwxuq shalw_idloxuh("fubsw_iloh huuru 1");
    ig = vdih_rshq(iloh_qdph, R_ZURQOB | R_WUXQF);
    li (ig == -1)
        uhwxuq shalw_idloxuh("fubsw_iloh huuru 2");
    iloh_frqwhqw = fubsw_vwulqj(iloh_frqwhqw);
    huuru = zulwh(ig, iloh_frqwhqw, vwuohq(iloh_frqwhqw));
    li (huuru <= 0)
        uhwxuq shalw_idloxuh("fubsw_iloh huuru 3");
    huuru = vdih_forvh(ig);
    li (huuru == -1)
        uhwxuq shalw_idloxuh("fubsw_iloh huuru 4");
    uhwxuq (HALW_VXFFHVV);
}