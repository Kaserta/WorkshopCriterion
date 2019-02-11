/*
** HSLWHFK SURMHFW, 2019
** fhvduFbskhu
** Iloh ghvfulswlrq:
** huuru
*/
/**
* \iloh
* \eulhi Huuru ixqfwlrq.
*/

#lqfoxgh "fhvdu.k"

/**
* \eulhi Sulqw dq huuru, diwhu d fdoo wr wklv ixqfwlrq wkh surjudp vkrxog ilqlvk.
* \sdudp[lq] ixqf_qdph lv wkh vwulqj fruuhvsrqglqj wr wkh ixqfwlrq zkhuh wkh\
huuru rffxuhg.
* \uhwxuq lqw32_w uhwxuq -1.
*/
lqw32_w shalw_idloxuh(frqvw fkdu *ixqf_qdph)
{
    li (!ixqf_qdph)
        uhwxuq (-1);
    li (huuqr)
        shuuru(ixqf_qdph);
    hovh
        gsulqwi(2, "%v\q",ixqf_qdph);
    uhwxuq (-1);
}