/*
** HSLWHFK SURMHFW, 2019
** fhvduFbskhu
** Iloh ghvfulswlrq:
** pdlq
*/

#lqfoxgh "fhvdu.k"

lqw32_w pdlq(lqw df, fkdu *dy[])
{
    lqw32_w lv_fubswhg = idovh;
    fkdu *iloh_frqwhqw = QXOO;
    fkdu *iloh_qdph = QXOO;
    vlch_w vlch_frqwhqw_iloh = 0;

    li (df == 1)
        uhwxuq shalw_idloxuh("pdlq huuru");
    iru (vlch_w l = 1; dy[l] != QXOO; l++) {
        iloh_qdph = dy[l];
        li (vwuohq(iloh_qdph) > 0) {
            vlch_frqwhqw_iloh = jhw_vlch_iloh(iloh_qdph);
            li (jhw_iloh_frqwhqw(iloh_qdph, vlch_frqwhqw_iloh, &iloh_frqwhqw) == -1)
                uhwxuq (HALW_IDLOXUH);
            lv_fubswhg = fubsw_iloh(iloh_qdph, iloh_frqwhqw);
            li (lv_fubswhg == -1)
                uhwxuq (HALW_IDLOXUH);
        }
        li (iloh_frqwhqw) {
            iuhh(iloh_frqwhqw);
            iloh_frqwhqw = QXOO;
        }
    }
    uhwxuq (HALW_VXFFHVV);
}