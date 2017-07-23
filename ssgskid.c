
int sub_16D18()
{
  char *value; // r0@1
  int ip; // r0@1
  int ip2; // r0@1
  int v3; // r4@2
  unsigned int addr4; // r0@3
  unsigned int addr5; // r0@3
  char *addr6; // r0@3
  int addr7; // r0@3
  int addr8; // r0@3
  int addr9; // r0@3
  int ip0; // r0@3
  char ip1; // r4@4
  int ip2; // r5@4
  int ip3; // r4@4
  int ip4; // r0@4
  int ip5; // r1@4
  char *ip6; // r5@4
  int ip7; // r0@4
  int ip8; // r0@4
  char *ip9; // r4@5
  int ip20; // r0@7
  int ip21; // r0@7
  int ip22; // r0@9
  int ip23; // r0@9
  const char *ip24; // r0@9
  int ip25; // r0@9
  int ip26; // r4@9
  int ip27; // r0@9
  int ip28; // r0@9
  int ip29; // r0@10
  int v30; // r0@12
  int v31; // r0@12
  int v32; // r4@12
  int v33; // r0@12
  int v34; // r0@12
  int v35; // r4@12
  int v36; // r0@12
  int v37; // r0@12
  int v38; // r0@13
  int v39; // r0@15
  int addr40; // r4@15
  int addr41; // r0@16
  int addr42; // r0@18
  int addr43; // r0@18
  int addr44; // r4@18
  int addr45; // r0@18
  int addr46; // r0@18
  int addr47; // r0@19
  int addr48; // r0@19
  int addr49; // r0@22
  int addr50; // r0@24
  int addr51; // r0@24
  int addr53; // [sp+10h] [bp-478h]@9
  int addr54; // [sp+A0h] [bp-3E8h]@9
  char addr55; // [sp+3C8h] [bp-C0h]@3
  char broadaddr; // [sp+3E8h] [bp-A0h]@3
  int ifconfig2; // [sp+408h] [bp-80h]@1
  int ifconfig1; // [sp+428h] [bp-60h]@1
  int mac; // [sp+448h] [bp-40h]@1
  int ifname; // [sp+45Ch] [bp-2Ch]@1
  struct in_addr inp; // [sp+470h] [bp-18h]@1
  struct in_addr addr1; // [sp+474h] [bp-14h]@1

  puts("<form method=post action=\"timepro.cgi\" name=\"netconf_lansetup\" style=\"margin:0; padding:0;\">");
  puts("<input type=hidden name=\"tmenu\" value=\"netconf\">");
  puts("<input type=hidden name=\"smenu\" value=\"lansetup\">");
  puts("<input type=hidden name=\"act\" value=\"\">");
  puts("<input type=hidden name=\"reboot\" value=\"\">");
  printf("<table class=\"v3_table lansetup_main_table\" width=\"100%%; padding:0; margin:0;\">\n");
  printf("<COL width=\"125\"><COL width=\"75\"><COL width=\"442\">");
  printf("<tr class=\"lansetup_main_tr\"><td class=\"lansetup_main_td\" width=\"100%%\" colspan=\"3\">");
  printf("<table class=\"v3_table lansetup_main_table\" width=\"100%%\">\n");
  printf("<COL width=\"110\"><COL width=\"160\"><COL width=\"240\"><COL width=\"%%%%\">");
  get_wan_ifname("wan1", &ifname);
  get_ifconfig(&ifname, &ifconfig1, &ifconfig2);
  inet_aton((const char *)&ifconfig1, &addr1);
  inet_aton((const char *)&ifconfig2, &inp);
  addr1.s_addr &= inp.s_addr;
  value = inet_ntoa(addr1);
  printf("<input type=hidden name=\"wan1subnet\" value=\"%s\">\n", value);
  ip = sub_134F4(389);
  printf(
    "<tr height=\"24\" class=\"lansetup_main_tr\" style=\"background-color:#%s;\">\t\t<td class=\"lansetup_main_td\" styl"
    "e=\"padding-left:5px;\">%s</td>",
    "FFFFFF",
    ip);
  get_ifconfig("br0", &ifconfig1, &ifconfig2);
  puts("<td class=\"lansetup_main_td\">");
  sub_11D7C("ip", &ifconfig1, 1);
  printf("</td><td colspan=\"2\" class=\"lansetup_main_td\">");
  get_hwaddr_kernel("br0", &mac);
  convert_mac(&mac);
  printf("<span class=\"lansetup_main_p\">(%s)</span>", &mac);
  puts("</td></tr>");
  ip2 = sub_134F4(907);
  printf(
    "<tr height=\"24\" class=\"lansetup_main_tr\" style=\"background-color:#%s;\">\t\t<td class=\"lansetup_main_td\" styl"
    "e=\"padding-left:5px;\">%s</td>",
    "F7F7F7",
    ip2);
  puts("<td class=\"lansetup_main_td\">");
  sub_11D7C("sm", &ifconfig2, 2);
  puts("</td><td colspan=\"2\" class=\"lansetup_main_td\"></td></tr>");
  if ( istatus_get_intvalue_direct("lanwan_samenetwork") == 1 )
  {
    get_localbroadaddr("br0", &broadaddr);
    addr4 = inet_addr(&broadaddr);
    addr5 = ((addr4 >> 24) | (addr4 << 24) | ((addr4 & 0xFF0000) >> 8) | ((unsigned __int16)(addr4 & 0xFF00) << 8)) + 2;
    addr6 = inet_ntoa((struct in_addr)((addr5 >> 24) | (addr5 << 24) | ((addr5 & 0xFF0000) >> 8) | ((unsigned __int16)(addr5 & 0xFF00) << 8)));
    strcpy(&addr5, addr6);
    printf((const char *)&unk_5C787, "FFFFFF");
    addr7 = sub_134F4(443);
    printf("<p>%s</p>", addr7);
    addr8 = sub_134F4(444);
    printf("<p>%s</p>", addr8);
    printf(
      "<p><input type=checkbox onclick=\"if(this.checked == true) SetIP('ip','%s'); else SetIP('ip','%s');\">",
      &addr55,
      &ifconfig1);
    addr9 = sub_134F4(442);
    v3 = 3;
    printf("%s</p>", addr9);
    ip0 = sub_134F4(445);
    printf("<p>%s</p>", ip0);
    puts("</span></td></tr>");
  }
  else
  {
    v3 = 2;
  }
  printf("</table>");
  printf("</td></tr>");
  printf("<tr class=\"lansetup_main_tr\"><td class=\"lansetup_main_td\" width=\"100%%\" colspan=\"3\">");
  ip1 = sub_16638(v3);
  printf("</td></tr>");
  printf((const char *)&unk_5C8A8);
  ip2 = sub_134F4(438);
  ip3 = sub_134F4(439);
  ip4 = sub_134F4(440);
  ip5 = ip2;
  ip6 = "checked";
  printf(
    "<span class=\"lansetup_main_p\">\t\t%s <a href=\"javascript:MovePagetoMainURL('sysconf', 'misc', 'service=hubapmode'"
    ");\" style=\"color:#0000FF;\"><u>%s</u></a> %s\t\t</span>",
    ip5,
    ip3,
    ip4);
  printf("</td></tr>");
  ip7 = sub_134F4(642);
  printf(
    "<tr height=\"26\" class=\"lansetup_main_tr\" style=\"background-color:#%s;\">\t\t<td class=\"lansetup_main_td\" styl"
    "e=\"padding-left:5px;\"><span class=\"lansetup_main_span\"><b>%s</b></span></td>",
    "DBDBDB",
    ip7);
  printf("<td class=\"lansetup_main_td\" colspan=2 align=\"right\">");
  ip8 = printf("<span class=\"lansetup_main_span\">");
  if ( get_ipmac_bind(ip8) & 1 )
    ip9 = "checked";
  else
    ip9 = "";
  ip20 = sub_134F4(513);
  printf(
    "<input type=\"checkbox\" name=\"mac_restrict\" onclick=\"onclick_macristrict();\" id=\"mrestid\" %s>\t\t<label for=\""
    "mrestid\">%s</label>",
    ip9,
    ip20);
  ip21 = printf("</span><span class=\"lansetup_main_span\" style=\"padding-right:17px;\">");
  if ( !get_dhcp_access_policy(ip21) )
    ip6 = "";
  ip22 = sub_134F4(648);
  printf(
    "<input type=\"checkbox\" class=\"navi_chk\" id=\"dhcppol\" name=\"dhcp_access_policy\" onclick=\"ApplyPartSubmit('dh"
    "cp_access_policy');\" %s>\t\t<label for=\"dhcppol\">%s</label>",
    ip6,
    ip22);
  printf("</span>");
  printf("</td></tr>");
  ip23 = sub_134F4(649);
  printf(
    "<tr height=\"24\" class=\"lansetup_main_tr\" style=\"background-color:#%s; border-bottom:1px #ccc solid; border-top:"
    "1px #ccc solid;\">\t\t<td class=\"lansetup_main_td\" colspan=2 style=\"padding-left:5px;\"><span class=\"lansetup_main_span\">%s",
    "EEEEEE",
    ip23);
  dhcpd_read_config(&addr53);
  ip24 = (const char *)sub_134F4(463);
  printf(ip24, addr54);
  printf("</span></td>");
  printf("<td class=\"lansetup_main_td\" align=\"right\" style=\"padding-right:17px;\">");
  ip25 = printf("<span class=\"lansetup_main_span\" style=\"margin-right:10px;\" onclick=\"RemoveStaticLease();\">");
  ip26 = sub_126C4(ip25);
  ip27 = sub_134F4(118);
  printf(
    "<img src=\"/%s/minus_icon.gif\" class=\"lansetup_main_span\" style=\"width:10px; height:10px;\">\t\t<span class=\"la"
    "nsetup_main_span\">%s</span>",
    ip26,
    ip27);
  printf("</span>");
  printf("<span class=\"lansetup_main_span\">");
  puts("<input type=\"checkbox\" name=\"del_allchk\" onclick=\"CheckAllCheckBox(static_lease.document, this, 'dellease');\">");
  printf("</span>");
  printf("</td></tr>");
  ip28 = printf("<tr class=\"lansetup_main_tr\" height=\"120\"><td class=\"lansetup_main_td\" colspan=\"3\">");
  if ( is_mobile_agent(ip28) )
  {
    sub_12790("120", "100%%", "display:inline-block; *display:inline; zoom:1;");
    ip29 = printf("<iframe name=\"static_lease\" src=\"timepro.cgi?tmenu=iframe&smenu=static_lease\"                         frameborder=no width=100%% height=120 align=center scrolling=yes></iframe>");
    sub_12770(ip29);
  }
  else
  {
    printf("<iframe name=\"static_lease\" src=\"timepro.cgi?tmenu=iframe&smenu=static_lease\"                         frameborder=no width=100%% height=120 align=center scrolling=yes></iframe>");
  }
  printf("</td></tr>");
  v30 = sub_134F4(650);
  printf(
    "<tr height=\"24\" class=\"lansetup_main_tr\" style=\"background-color:#%s; border-bottom:1px #ccc solid; border-top:"
    "1px #ccc solid;\">\t\t<td class=\"lansetup_main_td\" style=\"padding-left:5px;\"><span class=\"lansetup_main_span\">%s</span></td>",
    "EEEEEE",
    v30);
  printf("<td class=\"lansetup_main_td\" colspan=2 align=\"right\" style=\"padding-right:17px;\">");
  v31 = printf("<span class=\"lansetup_main_span\" style=\"margin-right:10px;\" onclick=\"onclick_research_span();\">");
  v32 = sub_126C4(v31);
  v33 = sub_134F4(465);
  printf((const char *)&unk_5D17C, v32, v33);
  printf("</span>");
  v34 = printf("<span class=\"lansetup_main_span\" style=\"margin-right:10px;\" onclick=\"AddStaticLease();\">");
  v35 = sub_126C4(v34);
  v36 = sub_134F4(435);
  printf(
    "<img src=\"/%s/plus_icon.gif\" class=\"lansetup_main_span\" style=\"width:10px; height:10px;\">\t\t<span class=\"lan"
    "setup_main_span\">%s</span>",
    v35,
    v36);
  printf("</span>");
  printf("<span class=\"lansetup_main_span\">");
  puts("<input type=\"checkbox\" name=\"add_allchk\" onclick=\"CheckAllCheckBox(lan_pcinfo.document, this, 'addlease');\">");
  printf("</span>");
  printf("</td></tr>");
  v37 = printf("<tr class=\"lansetup_main_tr\" height=\"120\"><td class=\"lansetup_main_td\" colspan=\"3\">");
  if ( is_mobile_agent(v37) )
  {
    sub_12790("120", "100%%", "display:inline-block; *display:inline; zoom:1;");
    v38 = printf("<iframe name=\"lan_pcinfo\" src=\"timepro.cgi?tmenu=iframe&smenu=lan_pcinfo\"                         frameborder=no width=100%% height=120 align=center scrolling=yes></iframe>");
    sub_12770(v38);
  }
  else
  {
    printf("<iframe name=\"lan_pcinfo\" src=\"timepro.cgi?tmenu=iframe&smenu=lan_pcinfo\"                         frameborder=no width=100%% height=120 align=center scrolling=yes></iframe>");
  }
  printf("</td></tr>");
  v39 = sub_134F4(466);
  addr40 = 0;
  printf(
    "<tr height=\"24\" class=\"lansetup_main_tr\" style=\"background-color:#%s; border-bottom:1px #ccc solid; border-top:"
    "1px #ccc solid;\">\t\t<td class=\"lansetup_main_td\" style=\"padding-left:5px;\" colspan=\"3\"><span class=\"lansetu"
    "p_main_span\">%s</span>",
    "EEEEEE",
    v39);
  printf("<span class=\"lansetup_main_span\" style=\"padding-left:15px;\">");
  sub_11D7C("manual_ip", 0, 3);
  printf("</span>");
  printf("<span class=\"lansetup_main_span\" style=\"padding-left:10px;\">");
  while ( 1 )
  {
    ++addr40;
    printf(
      "<input type=text name='%s%d' size=2 maxlength=2 style=\"width:18pt; ime-mode: disabled;\" onfocus='this.select();'"
      " onkeypress=\"return HWKeyDown('%s',%d);\" onkeyup=\"HWKeyUp('%s',%d);\"",
      "manual_hw",
      addr40,
      "manual_hw",
      addr40,
      "manual_hw",
      addr40);
    addr41 = sub_134F4(512);
    printf("title=\"%s%d\"", addr41, addr40);
    putchar(62);
    if ( addr40 == 6 )
      break;
    putchar(45);
  }
  printf("</span>");
  printf("<span class=\"lansetup_main_span\" style=\"padding-left:10px;\">");
  addr42 = sub_134F4(436);
  printf("<input type=\"text\" name=\"desc\" maxlength=\"20\" style=\"width:120px;\" placeholder=\"%s\">", addr42);
  printf("</span>");
  addr43 = printf("<span class=\"lansetup_main_span\" style=\"padding-left:15px;\" onclick=\"AddManualStaticLease();\">");
  addr44 = sub_126C4(addr43);
  addr45 = sub_134F4(467);
  printf(
    "<img src=\"/%s/plus_icon.gif\" class=\"lansetup_main_span\" style=\"width:10px; height:10px;\">\t\t<span class=\"lan"
    "setup_main_span\">%s</span>",
    addr44,
    addr45);
  printf("</span>");
  printf("</td></tr>");
  printf("</table>");
  printf("</form>");
  printf("<form method=\"post\" name=\"backup_lansetup\" style=\"padding:0; margin:0;\">");
  addr46 = printf("</form>");
  if ( is_mobile_agent(addr46) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    addr47 = printf("<iframe name=\"hiddenlansetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenlansetup\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
    addr48 = sub_12770(addr47);
  }
  else
  {
    addr48 = printf("<iframe name=\"hiddenlansetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenlansetup\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
  }
  if ( is_mobile_agent(addr48) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    addr49 = printf("<iframe name=\"hiddenlanstatus_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenlanstatus\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
    sub_12770(addr49);
  }
  else
  {
    printf("<iframe name=\"hiddenlanstatus_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenlanstatus\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
  }
  puts("<script language=JavaScript>");
  puts("init_netconf_lansetup();");
  puts("</script>");
  printf("<DIV id=\"%s\" style=\"display:none;\">", "apply_mask");
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:536px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:231px; top:198px; width:180px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"180\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  addr50 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  addr51 = sub_126C4(addr50);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    addr51);
  printf("</SPAN></td>");
  printf("<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\" id=\"lansetup_div_msg\">\n");
  printf("</SPAN></td>");
  printf("</tr></table></DIV>");
  printf("</DIV>");
  printf("<DIV id=\"%s\" style=\"display:none;\">", "info_mask");
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:536px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:151px; top:198px; width:340px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"340\" height=\"70\">");
  printf("<tr height=\"35\"><td width=\"1%%\" height=\"35\" align=\"center\" valign=\"middle\">\n");
  puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  printf("</SPAN></td>");
  printf("<td width=\"99%%\" height=\"35\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\" id=\"lansetup_div_info1\">\n");
  printf("</SPAN></td>");
  printf("</tr>");
  printf("<tr height=\"35\"><td width=\"1%%\" height=\"35\" align=\"center\" valign=\"middle\">\n");
  puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  printf("</SPAN></td>");
  printf("<td width=\"99%%\" height=\"35\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\" id=\"lansetup_div_info2\">\n");
  printf("</SPAN></td>");
  printf("</tr>");
  printf("</table></DIV>");
  return printf("</DIV>");
}


int sub_1D914()
{
  int v0; // r0@1
  int v1; // r4@1
  int v2; // r0@1
  int v3; // r0@1
  int v4; // r0@1
  int v5; // r4@1
  char *v6; // r0@2
  int v7; // r0@4
  int v8; // r0@4
  int v9; // r0@4
  int v10; // r4@4
  int v11; // r0@4
  int v12; // r0@4

  puts("<table cellspacing=0px cellpadding=0px>");
  printf("<colgroup><col width=150px></colgroup>");
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v0 = sub_134F4(918);
  v1 = v0;
  v2 = hwinfo_get_reboot_duration(v0);
  printf(
    "<input type=button name=save VALUE=\"%s\"  onclick=\"RestoreDefaultConfig(%d);\" style=\"width:120px;\">",
    v1,
    v2);
  puts("</td>");
  v3 = sub_134F4(919);
  v4 = printf("<td><span class=gray_text>%s</span></td>\n", v3);
  etr(v4);
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v5 = sub_134F4(965);
  if ( file_exists("/var/run/savefs.gz") )
    v6 = "";
  else
    v6 = (char *)sub_134F4(960);
  printf("<input type=button name=save VALUE=\"%s\" onclick=\"ApplyBackup('%s')\" style=\"width:120px;\">", v5, v6);
  puts("</td>");
  v7 = sub_134F4(966);
  printf("<td><span class=gray_text>%s</span></td>\n", v7);
  v8 = puts("</td>");
  etr(v8);
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v9 = sub_134F4(963);
  v10 = v9;
  v11 = hwinfo_get_reboot_duration(v9);
  printf("<input type=button name=save VALUE=\"%s\"  onclick=\"RestoreConfig(%d)\" style=\"width:120px;\">", v10, v11);
  puts("</td>");
  printf("<td>");
  printf("<iframe name=\"sysconf_misc_configmgmt_submit\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_misc_configmgmt_submit\" frameborder=no width=400px height=26px scrolling=no></iframe>");
  printf("<input type=file name=\"restore_config_file\" size=10 maxlength=120 style='width:300px; display: none; color: #888;' disabled>");
  v12 = printf("</td>");
  etr(v12);
  return puts("</table>");
}


int sub_17704()
{
  int v0; // r0@1
  int v1; // r1@2
  int v2; // r0@3

  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"netconf_hiddenlanstatus\">");
  puts("<input type=hidden name=\"tmenu\" value=\"iframe\">");
  puts("<input type=hidden name=\"smenu\" value=\"hiddenlanstatus\">");
  printf("</form>");
  printf("</BODY>");
  v0 = printf("<script>");
  if ( dhcpd_get_op(v0) && get_dhcp_auto_detect_status("br0") )
  {
    v2 = sub_134F4(447, v1);
    printf("parent.document.getElementById('dhcpstat').innerHTML = '%s';", v2);
  }
  else
  {
    printf("parent.document.getElementById('dhcpstat').innerHTML = '';");
  }
  printf("if(!parent.document.runstat || parent.document.runstat == 'run')");
  printf("parent.document.timeoutval = setTimeout(function(){document.netconf_hiddenlanstatus.submit();}, 5000);");
  return printf("</script>");
}


signed int __fastcall sub_177D0(int a1, int a2, const char *a3)
{
  int v3; // r7@1
  const char *v4; // r6@1
  int v5; // r5@1
  int v6; // r4@1
  bool v8; // nf@4
  unsigned __int8 v9; // vf@4
  const char *v10; // r0@4

  v3 = a2;
  v4 = a3;
  v5 = a1;
  v6 = 0;
  while ( 1 )
  {
    v9 = __OFSUB__(v6, v3);
    v8 = v6 - v3 < 0;
    v10 = (const char *)(v5 + 148);
    ++v6;
    if ( !(v8 ^ v9) )
      break;
    v5 += 188;
    if ( !strcmp(v10, v4) )
      return 1;
  }
  return 0;
}


int __fastcall sub_1781C(int a1)
{
  int v1; // r6@1
  int result; // r0@1
  int v3; // r10@3
  signed int v4; // r5@9
  signed int v5; // r7@12
  int v6; // r0@14
  signed int v7; // r3@20
  int v8; // r0@28
  signed int v9; // r4@30
  int v10; // r0@31
  int v11; // r4@32
  int v12; // r0@33
  int v13; // r0@33
  int v14; // r7@42
  int v15; // r5@42
  int v16; // r5@44
  int v17; // r0@46
  signed int v18; // r0@47
  int v19; // r0@49
  int v20; // r0@51
  int v21; // r4@53
  int v22; // r0@56
  int v23; // [sp+0h] [bp-488h]@6
  int v24; // [sp+10h] [bp-478h]@8
  int v25; // [sp+24h] [bp-464h]@8
  char v26; // [sp+38h] [bp-450h]@8
  int v27; // [sp+4Ch] [bp-43Ch]@8
  int v28; // [sp+60h] [bp-428h]@8
  char v29; // [sp+74h] [bp-414h]@26
  char v30; // [sp+8Ch] [bp-3FCh]@26
  char v31; // [sp+94h] [bp-3F4h]@22
  int v32; // [sp+3B4h] [bp-D4h]@22
  char v33; // [sp+3B8h] [bp-D0h]@43
  char s1; // [sp+3D8h] [bp-B0h]@1
  char v35; // [sp+3F8h] [bp-90h]@2
  int v36; // [sp+418h] [bp-70h]@8
  int v37; // [sp+42Ch] [bp-5Ch]@8
  char v38; // [sp+440h] [bp-48h]@7
  int v39; // [sp+454h] [bp-34h]@6

  v1 = a1;
  result = get_value_post(a1, "act", &s1, 32);
  if ( !result )
    return result;
  if ( get_value_post(v1, "reboot", &v35, 32) )
    v3 = strcmp(&v35, "reboot") == 0;
  else
    v3 = 0;
  if ( !strcmp(&s1, "submit") )
  {
    dhcpd_read_config(&v23);
    strcpy((char *)&v39, "");
    if ( get_ip_value_post(v1, "ip", &v39) && get_ip_value_post(v1, "sm", &v38) )
    {
      set_use_local_gateway(0);
      set_lan_ipconfig(&v39, &v38, 0);
      sf_strncpy(&v26, &v39, 20);
      sf_strncpy(&v27, &v38, 20);
      get_subnet_range(&v39, &v38, &v24, &v25);
      get_ifconfig((int)"br0", (int)&v37, (int)&v36);
      if ( !strcmp((const char *)&v28, (const char *)&v37) )
      {
        v4 = 1;
        sf_strncpy(&v28, &v39, 20);
      }
      else
      {
        v4 = 1;
      }
    }
    else
    {
      v4 = 0;
    }
    v5 = v4;
    if ( get_value_post(v1, "dhcp_enable", &v35, 32) && !strcmp(&v35, "on") )
    {
      v6 = dhcpd_set_op(1);
      dhcpd_stop(v6);
      if ( get_value_post(v1, "miprange", &v35, 32) && !strcmp(&v35, "on") )
      {
        if ( get_ip_value_post(v1, "spool_conf", &v35) )
          sf_strncpy(&v24, &v35, 20);
        if ( get_ip_value_post(v1, "epool_conf", &v35) )
          sf_strncpy(&v25, &v35, 20);
        v7 = 1;
      }
      else
      {
        v7 = 0;
      }
      v32 = v7;
      if ( !get_value_post(v1, "domain", &v31, 32) )
        strcpy(&v31, "");
      if ( check_unpermitted_chars(&v31) )
        strcpy(&v31, "");
      get_intvalue_post(v1, "leasetime", &v30);
      get_domain_name_server(&v28, &v29);
      set_autodns(1);
      v8 = get_value_post(v1, "dhcp_auto_detect", &v35, 32) && !strcmp(&v35, "on");
      set_dhcp_auto_detect(v8);
      syslog_msg(1, "@{43}");
      v9 = 1;
    }
    else
    {
      v10 = get_value_post(v1, "dhcp_enable", &v35, 32);
      if ( v10 )
      {
        v10 = strcmp(&v35, "off");
        v11 = v10;
        if ( !v10 )
        {
          dhcpd_set_op(0);
          set_dhcp_auto_detect(v11);
          set_dhcp_access_policy(v11);
          v12 = syslog_msg(2, "@{44}");
          v13 = check_twinip_enable(v12);
          if ( v13 )
            v13 = dhcpd_start(v13);
          v10 = dhcpd_stop(v13);
          v5 = 1;
        }
      }
      v9 = 0;
      if ( !v4 )
      {
LABEL_37:
        if ( v5 )
          v10 = dhcpd_flush_dynamic_lease(v10);
        if ( v9 )
          v10 = dhcpd_start(v10);
        if ( v3 )
        {
          v14 = hwinfo_get_reboot_duration(v10);
          v10 = check_remote_connection();
          v15 = v10;
          if ( !v10 )
          {
            get_ip_value_post(v1, "ip", &v39);
            v10 = sf_strncpy(&v33, &v39, 32);
          }
          v21 = v14 + 30;
          goto LABEL_54;
        }
        goto LABEL_55;
      }
    }
    v10 = dhcpd_commit_config(&v23);
    goto LABEL_37;
  }
  v10 = strcmp(&s1, "part");
  v16 = v10;
  if ( !v10 )
  {
    if ( get_value_post(v1, "dhcp_access_policy", &v35, 32) )
    {
      v17 = dhcpd_set_op(1);
      dhcpd_stop(v17);
      if ( !strcmp(&v35, "on") )
        v18 = 1;
      else
        v18 = v16;
      v19 = set_dhcp_access_policy(v18);
      dhcpd_start(v19);
    }
    v10 = get_value_post(v1, "mac_restrict", &v35, 32);
    if ( v10 )
    {
      v20 = strcmp(&v35, "on") == 0;
      v10 = set_ipmac_bind();
    }
  }
  if ( v3 )
  {
    v15 = 0;
    v21 = 0;
LABEL_54:
    v10 = saveconf(v10);
    goto LABEL_56;
  }
LABEL_55:
  v15 = 0;
  v21 = 0;
LABEL_56:
  v22 = signal_update(v10);
  result = signal_save(v22);
  if ( v3 )
  {
    printf("<script>");
    if ( !v15 )
      printf("document.refreshURL = '%s';\n", &v33);
    printf("document.rebootDuration = %d;", v21);
    printf("</script>");
    result = signal_reboot(3);
  }
  return result;
}


int __fastcall sub_17DA0(int a1, int a2)
{
  int v2; // r4@1

  v2 = a2;
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"netconf_hiddenlansetup\">");
  printf("</form>");
  printf("</BODY>");
  sub_1781C(v2);
  printf("<script>");
  puts("if(document.rebootDuration && parent.window.lansetup_reboot_process){");
  puts("parent.window.lansetup_reboot_process(document.rebootDuration, document.refreshURL);}");
  printf("else{UnMaskIt(parent.document,'apply_mask');}");
  return printf("</script>");
}




void __fastcall sub_17E20(int a1, signed int a2)
{
  signed int v2; // r7@1
  int v3; // r0@10
  int v4; // r3@15
  bool v5; // zf@15
  unsigned int v6; // r2@15
  char v7; // r3@15
  const char *v8; // r0@20
  char *v9; // r1@20
  char *v10; // r0@21
  int v11; // r5@25
  int v12; // r0@26
  int v13; // r4@27
  int v14; // r0@34
  int v15; // r0@34
  int v16; // r0@36
  char *v17; // r0@36
  signed int v18; // r6@39
  void *v19; // r11@41
  int v20; // r7@41
  void *i; // r5@41
  bool v22; // nf@48
  unsigned __int8 v23; // vf@48
  int v24; // r6@51
  char *v25; // r0@52
  char *v26; // r0@52
  int v27; // r5@52
  int v28; // r1@52
  const char *v29; // r0@52
  int v30; // r1@52
  int v31; // r0@53
  int v32; // r0@55
  signed int v33; // r6@55
  signed int v34; // r1@56
  char *v35; // r0@58
  char *v36; // r0@60
  int v37; // r10@60
  int v38; // r5@65
  int v39; // r1@65
  const char *v40; // r0@65
  int v41; // r1@65
  int v42; // r0@66
  int v43; // r0@68
  signed int v44; // r1@69
  int v45; // r4@18
  int *v46; // [sp+0h] [bp-2E0h]@0
  int *v47; // [sp+4h] [bp-2DCh]@0
  int *v48; // [sp+8h] [bp-2D8h]@0
  int *v49; // [sp+Ch] [bp-2D4h]@0
  void *ptr; // [sp+10h] [bp-2D0h]@36
  int v51; // [sp+14h] [bp-2CCh]@36
  signed int v52; // [sp+18h] [bp-2C8h]@2
  int v53; // [sp+1Ch] [bp-2C4h]@49
  char v54; // [sp+24h] [bp-2BCh]@52
  char v55; // [sp+124h] [bp-1BCh]@52
  char v56; // [sp+150h] [bp-190h]@52
  char v57; // [sp+190h] [bp-150h]@18
  char v58; // [sp+1D0h] [bp-110h]@27
  char v59; // [sp+1F0h] [bp-F0h]@3
  int v60; // [sp+218h] [bp-C8h]@17
  int v61; // [sp+21Ch] [bp-C4h]@17
  int v62; // [sp+220h] [bp-C0h]@17
  int v63; // [sp+224h] [bp-BCh]@17
  char v64; // [sp+228h] [bp-B8h]@22
  char v65; // [sp+240h] [bp-A0h]@7
  char s[20]; // [sp+254h] [bp-8Ch]@8
  char v67; // [sp+268h] [bp-78h]@52
  char s1; // [sp+27Ch] [bp-64h]@36
  char v69; // [sp+290h] [bp-50h]@36
  char v70; // [sp+2A4h] [bp-3Ch]@36

  v2 = a2;
  if ( !a2 )
  {
    v52 = a2;
    goto LABEL_36;
  }
  if ( get_value_post(a2, "act", &v59, 32) && !strcmp(&v59, "add") )
  {
    if ( !get_value_post(v2, "manual_check", &v59, 32) || strcmp(&v59, "on") )
    {
      v11 = 0;
      while ( 1 )
      {
        v46 = (int *)32;
        v12 = get_value_array_post(v2, "addlease", v11++, &v59);
        v5 = v12 == 0;
        v10 = &v59;
        if ( v5 )
          break;
        v13 = atoi(&v59);
        sprintf(&v58, "m%d", v13);
        v5 = get_value_post(v2, &v58, s, 20) == 0;
        v10 = s;
        if ( v5 )
          break;
        v5 = check_unpermitted_chars(s) == 0;
        v10 = &v58;
        if ( !v5 )
          break;
        sprintf(&v58, "i%d", v13);
        v5 = get_value_post(v2, &v58, &v65, 20) == 0;
        v10 = &v65;
        if ( v5 )
          break;
        v5 = check_unpermitted_chars(&v65) == 0;
        v10 = &v65;
        if ( !v5 )
          break;
        dhcpd_add_static_lease(&v65, s);
      }
      goto LABEL_34;
    }
    if ( get_value_post(v2, "manual_ip", &v65, 20) )
    {
      if ( get_value_post(v2, "manual_hw", s, 20) )
      {
        if ( !check_unpermitted_chars(&v65) )
        {
          v3 = check_unpermitted_chars(s);
          if ( !v3 )
          {
            while ( 1 )
            {
              v4 = (unsigned __int8)s[v3];
              v5 = v4 == 0;
              v6 = v4 - 97;
              v7 = v4 - 32;
              if ( v5 )
                break;
              if ( v6 <= 0x19 )
                s[v3] = v7;
              ++v3;
            }
            v46 = &v60;
            v47 = &v61;
            v48 = &v62;
            v49 = &v63;
            if ( sscanf(s, "%02X:%02X:%02X:%02X:%02X:%02X") == 6 )
            {
              snprintf2(&v57, 64, "slease_%s", s, &v60, &v61, &v62, &v63);
              v45 = dhcpd_add_static_lease(&v65, s);
              convert_mac(s);
              if ( v45 == 1 )
              {
                v9 = &v65;
                v8 = "<script> alert(STATIC_LEASE_ALREADY_EXIST_IPADDRESS + ':%s'); </script>";
              }
              else
              {
                if ( v45 != 2 )
                {
                  v10 = (char *)get_value_post(v2, "desc", &v64, 24);
                  if ( v10 )
                  {
                    v10 = (char *)check_unpermitted_chars(&v64);
                    if ( !v10 )
                      v10 = (char *)iconfig_set_value_direct(&v57, &v64);
                  }
                  goto LABEL_34;
                }
                v8 = "<script> alert(STATIC_LEASE_ALREADY_EXIST_HWADDRESS + ':%s'); </script>";
                v9 = s;
              }
              v10 = (char *)printf(v8, v9);
LABEL_34:
              v14 = dhcpd_stop(v10);
              v52 = 1;
              v15 = dhcpd_start(v14);
              signal_save(v15);
              goto LABEL_36;
            }
          }
        }
      }
    }
  }
  v52 = 0;
LABEL_36:
  ptr = malloc(0xBC00u);
  memset(ptr, 0, 0xBC00u);
  v51 = get_hostinfo_from_arp("br0", 256, ptr);
  v16 = get_ifconfig((int)"br0", (int)&v70, (int)&v69);
  sub_1644C(v16);
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0;\">");
  puts("<script>");
  puts("function ClickEventPropagater(e){");
  puts("if(!e) e = window.event;");
  printf("e.cancelbubble = true; if(e.stopPropagation)\te.stopPropagation();");
  puts("}");
  puts("</script>");
  printf("<form name=\"lan_pcinfo_fm\" method=\"post\" style=\"padding:0; margin:0;\">");
  printf("<input type=hidden name=tmenu value=iframe>");
  printf("<input type=hidden name=smenu value=lan_pcinfo>");
  printf("<input type=hidden name=act value=>");
  printf("<input type=hidden name=clickedbg value=>");
  printf("<input type=hidden name=clickedid value=>");
  printf("<input type=hidden name=manual_check value=>");
  printf("<input type=hidden name=manual_ip value=>");
  printf("<input type=hidden name=manual_hw value=>");
  printf("<input type=hidden name=desc value=>");
  printf("<table class=\"lansetup_main_table\" style=\"width:100%%;\">\n");
  printf("<COL width=\"110\"><COL width=\"160\"><COL width=\"150\"><COL width=\"130\"><COL width=\"%%%%\">");
  v17 = getenv("REMOTE_ADDR");
  get_internal_pc_hardware_address(v17, &s1);
  v18 = s1 && sub_177D0((int)ptr, v51, &s1) && !dhcpd_search_static_lease(0, &s1);
  v19 = ptr;
  v20 = 0;
  for ( i = ptr; ; i = (char *)i + 188 )
  {
    v23 = __OFSUB__(v20, v51);
    v22 = v20++ - v51 < 0;
    if ( !(v22 ^ v23) )
      break;
    if ( !dhcpd_search_static_lease((char *)i + 128, 0)
      && !dhcpd_search_static_lease(0, (char *)i + 148)
      && strcmp(&s1, (const char *)i + 148)
      && check_same_network((char *)i + 128, &v70, &v69) )
    {
      ++v18;
    }
  }
  v53 = v18 > 5;
  if ( s1 && sub_177D0((int)ptr, v51, &s1) && (v24 = dhcpd_search_static_lease(0, &s1)) == 0 )
  {
    printf(
      "<tr class=\"lansetup_main_tr\" height=\"24\" style=\"background-color:#%s; cursor:pointer;\" id=\"addlease_line%d\""
      " \t\t\t\tonclick=\"if(parent.window.onclick_list_tr)parent.window.onclick_list_tr(document, %d);\">",
      "FFFFFF",
      0,
      0,
      v46,
      v47,
      v48,
      v49);
    printf("<td class=\"lansetup_main_td\">");
    v25 = getenv("REMOTE_ADDR");
    printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>", v25);
    printf("</td>");
    printf("<td class=\"lansetup_main_td\">");
    sf_strncpy(&v67, &s1, 20);
    convert_mac(&s1);
    printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>", &s1);
    printf("</td>");
    convert_mac2(&s1);
    sf_strncpy(&s1, &v67, 20);
    memset(&v55, 0, 0x6Cu);
    v26 = getenv("REMOTE_ADDR");
    v27 = dhcpd_get_dynamic_lease(v26, &v55);
    printf("<td class=\"lansetup_main_td\">");
    memset(&v54, 0, 0x100u);
    convert_euckr_to_utf8(&v56, &v54);
    printf(
      "<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:145px; padding-left:5px\">%s</span>",
      &v54);
    printf("</td>");
    printf("<td class=\"lansetup_main_td\">");
    printf("<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:130px; padding-left:5px\">");
    v29 = (const char *)sub_134F4(472, v28);
    printf(v29);
    if ( v27 )
      v31 = 441;
    else
      v31 = 469;
    v32 = sub_134F4(v31, v30);
    v33 = 1;
    printf(":%s</span>", v32);
    printf("</td>");
    printf("<td class=\"lansetup_main_td\" align=\"right\">");
    if ( v53 )
      v34 = 5;
    else
      v34 = 17;
    printf((const char *)&unk_5E9C1, v34);
    printf("</td>");
    printf("</tr>");
    printf("<input type=\"hidden\" name=m%d value=\"%s\">\n", 0, &s1);
    v35 = getenv("REMOTE_ADDR");
    printf("<input type=\"hidden\" name=i%d value=\"%s\">\n", 0, v35);
    printf("<input type=\"hidden\" name=h%d value=\"%s\">\n", 0, &v54);
    printf("<input type=\"hidden\" name=\"curpc\" value=\"1\">");
  }
  else
  {
    v33 = 0;
  }
  v36 = getenv("REMOTE_ADDR");
  get_internal_pc_hardware_address(v36, &s1);
  v37 = 0;
  while ( v37 < v51 )
  {
    if ( !dhcpd_search_static_lease((char *)v19 + 128, 0)
      && !dhcpd_search_static_lease(0, (char *)v19 + 148)
      && strcmp(&s1, (const char *)v19 + 148)
      && check_same_network((char *)v19 + 128, &v70, &v69) )
    {
      printf("<tr class=\"lansetup_main_tr\" height=\"24\" style=\"background-color:#%s; cursor:pointer;\" id=\"addlease_line%d\" \t\t\tonclick=\"if(parent.window.onclick_list_tr)parent.window.onclick_list_tr(document, %d);\">");
      printf("<td class=\"lansetup_main_td\">");
      *((_BYTE *)v19 + 128);
      printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>");
      printf("</td>");
      sf_strncpy(&v67, (char *)v19 + 148, 20);
      convert_mac((char *)v19 + 148);
      printf("<td class=\"lansetup_main_td\">");
      printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>", (char *)v19 + 148);
      printf("</td>");
      convert_mac2((char *)v19 + 148);
      sf_strncpy((char *)v19 + 148, &v67, 20);
      memset(&v55, 0, 0x6Cu);
      v38 = dhcpd_get_dynamic_lease((char *)v19 + 128, &v55);
      printf("<td class=\"lansetup_main_td\">");
      memset(&v54, 0, 0x100u);
      convert_euckr_to_utf8(&v56, &v54);
      printf(
        "<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:145px; padding-left:5px\">%s</span>",
        &v54);
      printf("</td>");
      printf("<td class=\"lansetup_main_td\">");
      printf("<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:130px; padding-left:5px\">");
      v40 = (const char *)sub_134F4(472, v39);
      printf(v40);
      if ( v38 )
        v42 = 441;
      else
        v42 = 469;
      v43 = sub_134F4(v42, v41);
      printf(":%s</span>", v43);
      printf("</td>");
      printf("<td class=\"lansetup_main_td\" align=\"right\">");
      if ( v53 )
        v44 = 5;
      else
        v44 = 17;
      printf(
        "<span class=\"lansetup_main_span\" style=\"padding-right:%dpx;\">\t\t\t<input type=\"checkbox\" class=navi_chk n"
        "ame=\"addlease\" id=\"addlease%d\" value=\"%d\" \t\t\tonclick=\"ClickEventPropagater(event);\">\t\t\t</span>",
        v44,
        v33,
        v33,
        v46,
        v47,
        v48,
        v49);
      printf("</td>");
      printf("</tr>");
      printf("<input type=hidden name=m%d value=\"%s\">\n", v33, (char *)v19 + 148);
      printf("<input type=hidden name=i%d value=\"%s\">\n", v33, (char *)v19 + 128);
      printf("<input type=hidden name=h%d value=\"%s\">\n", v33++, &v54);
    }
    ++v37;
    v19 = (char *)v19 + 188;
  }
  while ( v33 <= 4 )
  {
    printf("<tr class=\"lansetup_main_tr\" height=\"24\"style=\"background-color:#%s\">");
    printf("<td class=\"lansetup_main_td\" colspan=\"5\"></td>");
    printf("</tr>");
    ++v33;
  }
  puts("</table>");
  puts("</form>");
  puts("</BODY>");
  puts("<script>");
  if ( v52 )
    puts("if(parent.window.AddPostSubmit)parent.window.AddPostSubmit();");
  printf("</script>");
  free(ptr);
}


int __fastcall sub_18844(int a1, signed int a2)
{
  signed int v2; // r6@1
  int i; // r5@6
  bool v4; // zf@7
  char *v5; // r0@7
  int v6; // r0@10
  signed int v7; // r11@12
  void *v8; // r7@15
  int v9; // r10@15
  int v10; // r0@16
  int v11; // r4@20
  void *v12; // r6@20
  void *v13; // r5@20
  int v14; // r9@20
  int v15; // r1@21
  bool v16; // nf@22
  unsigned __int8 v17; // vf@22
  const char *v18; // r0@22
  int v19; // r0@24
  signed int v20; // r1@26
  char *v21; // r12@28
  char *v22; // r0@30
  signed int j; // r4@34
  int result; // r0@37
  signed int v25; // [sp+0h] [bp-1C0h]@0
  void *base; // [sp+8h] [bp-1B8h]@12
  int nmemb; // [sp+Ch] [bp-1B4h]@12
  signed int v28; // [sp+10h] [bp-1B0h]@2
  int v29; // [sp+14h] [bp-1ACh]@18
  char s; // [sp+1Ch] [bp-1A4h]@18
  char v31; // [sp+11Ch] [bp-A4h]@19
  char v32; // [sp+15Ch] [bp-64h]@3
  char v33; // [sp+170h] [bp-50h]@7
  char v34; // [sp+184h] [bp-3Ch]@16

  v2 = a2;
  if ( a2 )
  {
    if ( get_value_post(a2, "act", &v32, 20) || (a1 = strcmp(&v32, "remove")) == 0 )
    {
      for ( i = 0; ; ++i )
      {
        v25 = 20;
        v4 = get_value_array_post(v2, "dellease", i, &v33) == 0;
        v5 = &v33;
        if ( v4 )
          break;
        dhcpd_remove_static_lease(&v33);
      }
      if ( i )
      {
        v6 = dhcpd_stop(&v33);
        v5 = (char *)dhcpd_start(v6);
      }
      a1 = signal_save(v5);
      v28 = 1;
    }
    else
    {
      v28 = 0;
    }
  }
  else
  {
    v28 = a2;
  }
  sub_1644C(a1);
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0;\">");
  puts("<script>");
  puts("function ClickEventPropagater(e){");
  puts("if(!e) e = window.event;");
  printf("e.cancelbubble = true; if(e.stopPropagation)\te.stopPropagation();");
  puts("}");
  puts("</script>");
  printf("<form name=\"static_lease_fm\" method=\"post\" style=\"padding:0; margin:0;\">");
  printf("<input type=hidden name=tmenu value=iframe>");
  printf("<input type=hidden name=smenu value=static_lease>");
  printf("<input type=hidden name=act value=>");
  printf("<table class=\"lansetup_main_table\" style=\"width:100%%;\">\n");
  printf("<COL width=\"110\"><COL width=\"160\"><COL width=\"150\"><COL width=\"130\"><COL width=\"%%%%\">");
  v7 = 0;
  base = malloc(0x6C00u);
  memset(base, 0, 0x6C00u);
  nmemb = dhcpd_get_all_static_lease(base, 256);
  qsort(base, nmemb, 0x6Cu, (__compar_fn_t)sub_165E4);
  while ( v7 < nmemb )
    ++v7;
  v8 = base;
  v9 = 0;
  while ( v9 < nmemb )
  {
    printf("<tr class=\"lansetup_main_tr\" height=\"24\" style=\"background-color:#%s; cursor:pointer;\" \t\t\tonclick=\"if(parent.window.onclick_static_tr)parent.window.onclick_static_tr(document, %d);\">");
    v10 = get_wan_ip("wan1", &v34);
    if ( v10 )
      v10 = strcmp(&v34, (const char *)v8) == 0;
    v29 = v10;
    memset(&s, 0, 0x100u);
    sf_strncpy(&s, (char *)v8 + 44, 256);
    if ( !s )
    {
      snprintf2(&v31, 64, "slease_%s", (char *)v8 + 20, v25);
      iconfig_get_value_direct(&v31, &s);
    }
    printf("<td class=\"lansetup_main_td\">");
    printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>", v8);
    printf("</td>");
    convert_mac((char *)v8 + 20);
    printf("<td class=\"lansetup_main_td\">");
    printf("<span class=\"lansetup_main_span\" style=\"padding-left:5px\">%s</span>", (char *)v8 + 20);
    printf("</td>");
    convert_mac2((char *)v8 + 20);
    printf("<td class=\"lansetup_main_td\">");
    printf("<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:145px; padding-left:5px\">%s</span>", &s);
    printf("</td>");
    printf("<td class=\"lansetup_main_td\">");
    memset(&s, 0, 0x100u);
    v11 = 0;
    v12 = malloc(0xBC00u);
    v13 = v12;
    v14 = get_hostinfo_from_bridge(1, 256, v12);
    while ( 1 )
    {
      v17 = __OFSUB__(v11, v14);
      v16 = v11 - v14 < 0;
      v18 = (char *)v13 + 148;
      ++v11;
      if ( !(v16 ^ v17) )
        break;
      v13 = (char *)v13 + 188;
      if ( !strcasecmp(v18, (const char *)v8 + 20) )
      {
        v19 = sub_134F4(472, v15);
        sf_strncpy(&s, v19, 256);
        break;
      }
    }
    free(v12);
    printf("<span class=\"lansetup_main_span lansetup_ellipsis\" style=\"width:130px; padding-left:5px\">%s</span>", &s);
    printf("</td>");
    printf("<td class=\"lansetup_main_td\" align=\"right\">");
    if ( v7 <= 5 )
      v20 = 17;
    else
      v20 = 5;
    v21 = "disabled";
    if ( !v29 )
      v21 = "";
    printf(
      "<span class=\"lansetup_main_span\" style=\"padding-right:%dpx;\">\t\t\t<input type=\"checkbox\" class=navi_chk nam"
      "e=\"dellease\" id=\"dellease%d\" value=\"%s\" \t\t\tonclick=\"ClickEventPropagater(event);\" %s></span>",
      v20,
      v9,
      v8,
      v21);
    printf("</td>");
    printf("</tr>");
    v22 = getenv("REMOTE_ADDR");
    if ( !strcmp(v22, (const char *)v8) )
      printf("<input type=\"hidden\" name=\"curpc\" value=\"1\">");
    ++v9;
    v8 = (char *)v8 + 108;
  }
  for ( j = v9; j <= 4; ++j )
  {
    printf("<tr class=\"lansetup_main_tr\" height=\"24\"style=\"background-color:#%s\">");
    printf("<td class=\"lansetup_main_td\" colspan=\"5\"></td>");
    printf("</tr>");
  }
  free(base);
  puts("</table>");
  puts("</form>");
  result = puts("</BODY>");
  if ( v28 )
    result = printf("<script> if(parent.window.RemovePostSubmit)parent.window.RemovePostSubmit(); </script>");
  return result;
}


signed int __fastcall sub_18CFC(int a1)
{
  int v1; // r5@1
  int v2; // r0@12
  int v3; // r0@18
  int v4; // r0@21
  int v5; // r0@22
  char v7; // [sp+0h] [bp-170h]@4
  char dest; // [sp+80h] [bp-F0h]@4
  char v9; // [sp+100h] [bp-70h]@9
  char v10; // [sp+120h] [bp-50h]@1
  char v11; // [sp+140h] [bp-30h]@11
  char v12; // [sp+150h] [bp-20h]@19

  v1 = a1;
  if ( !get_value_post(a1, "act", &v10, 31) )
    return 0;
  if ( strcmp(&v10, "save") )
  {
    if ( !strcmp(&v10, (const char *)&unk_5F0E6) )
    {
      strcpy(&v9, "");
      if ( get_value_post(v1, "http_auth", &v9, 15) )
      {
        set_http_auth_method(&v9);
        if ( !strcmp(&v9, "session") )
        {
          if ( get_value_post(v1, "use_captcha", &v11, 16) )
          {
            v2 = strcmp(&v11, "off");
            if ( v2 )
            {
              if ( !strcmp(&v11, "manual") )
                v2 = 2;
              else
                v2 = 1;
            }
            set_use_captcha_code(v2);
          }
          if ( get_value_post(v1, "captcha_attempt", &v11, 16) )
          {
            v3 = atoi(&v11);
            set_client_login_trial_count_without_captchar(v3);
          }
          strcpy(&v12, "");
          if ( get_value_post(v1, "http_session_timeout", &v12, 15) && v12 )
          {
            v4 = atoi(&v12);
            httpcon_set_session_timeout(60 * v4);
          }
        }
      }
      goto LABEL_22;
    }
    return 0;
  }
  if ( !sub_13298(v1) )
    return 0;
  strcpy(&dest, "");
  strcpy(&v7, "");
  get_value_post(v1, "new_passwd", &dest, 127);
  get_value_post(v1, &unk_5F0D6, &v7, 127);
  if ( check_unpermitted_chars(&v7) || !v7 && !dest )
    return 0;
  save_password(&v7, &dest);
LABEL_22:
  v5 = syslog_msg(1, "@{37}");
  signal_save(v5);
  signal_start("httpd");
  puts("<script>");
  puts("function GotoLoginPage(method)\n\t\t{\n\t\t\tif(method == 'session')\n\t\t\t\ttop.location.href='/sess-bin/login_session.cgi?logout=1';\n\t\t\telse if(method == 'basic')\n\t\t\t\ttop.location.href='/login/login.cgi';\n\t\t}");
  strcpy(&v9, "");
  get_http_auth_method(&v9);
  if ( v9 )
    printf("setTimeout(\"GotoLoginPage('%s')\", 4000);\n", &v9);
  puts("</script>");
  return 1;
}


int __fastcall sub_18FAC(int a1, int a2)
{
  int v2; // r5@1
  signed int v3; // r6@1
  char *v4; // r0@5
  char *v5; // r0@9
  char *v6; // r0@13
  int v7; // r0@15
  char *v8; // r0@20
  char *v9; // r0@23
  int v10; // r0@25
  int v11; // r0@29
  int v13; // [sp+0h] [bp-B0h]@3
  char v14; // [sp+80h] [bp-30h]@1

  v2 = a2;
  v3 = sub_18CFC(a2);
  if ( get_value_post(v2, "act", &v14, 32) )
  {
    if ( !strcmp(&v14, "apply_email") )
    {
      if ( !get_value_post(v2, "email", &v13, 128) || check_unpermitted_chars(&v13) )
        v4 = "";
      else
        v4 = (char *)&v13;
      set_admin_email(v4);
      if ( !get_value_post(v2, "smtp", &v13, 128) || check_unpermitted_chars(&v13) )
        v5 = "";
      else
        v5 = (char *)&v13;
      set_smtp_server(v5);
      if ( !get_value_post(v2, &unk_5F238, &v13, 128) || check_unpermitted_chars(&v13) )
        v6 = "";
      else
        v6 = (char *)&v13;
      set_send_email(v6);
      v7 = get_value_post(v2, "smtp_auth", &v13, 128);
      if ( v7 )
      {
        if ( !strcmp((const char *)&v13, "on") )
        {
          set_smtp_auth(1);
          if ( !get_value_post(v2, "account", &v13, 128) || check_unpermitted_chars(&v13) )
            v8 = "";
          else
            v8 = (char *)&v13;
          set_smtp_account(v8);
          if ( get_value_post(v2, "smtp_pass", &v13, 128) )
            v9 = (char *)&v13;
          else
            v9 = "";
          v10 = set_smtp_password(v9);
          goto LABEL_29;
        }
        v7 = 0;
      }
    }
    else
    {
      if ( strcmp(&v14, "delete_email") )
        goto LABEL_30;
      set_admin_email("");
      set_smtp_server("");
      set_send_email("");
      set_smtp_account("");
      set_smtp_password("");
      v7 = 0;
    }
    v10 = set_smtp_auth(v7);
LABEL_29:
    v11 = signal_update(v10);
    signal_save(v11);
  }
LABEL_30:
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"sysconf_hiddenloginsetup\">");
  printf("</form>");
  printf("</BODY>");
  printf("<script>");
  printf("UnMaskIt(parent.document, 'apply_mask');");
  if ( v3 )
    printf("MaskIt(parent.document, 'relogin_mask');");
  return printf("</script>");
}


int sub_1922C()
{
  int v0; // r1@1
  int v1; // r0@1
  int v2; // r0@1
  int v3; // r4@1
  int v4; // r1@1
  int v5; // r0@1
  int v6; // r1@1
  int v7; // r0@1
  int v8; // r1@1
  int v9; // r0@1
  int v10; // r1@1
  int v11; // r0@1
  char *v12; // r4@1
  int v13; // r1@1
  int v14; // r0@1
  int v15; // r0@1
  int v16; // r1@1
  char *v17; // r5@2
  int v18; // r0@4
  int v19; // r0@4
  int v20; // r1@4
  int v21; // r0@6
  int v22; // r1@6
  int v23; // r0@6
  int v24; // r1@6
  int v25; // r0@6
  int v26; // r1@6
  int v27; // r0@6
  int v29; // [sp+0h] [bp-298h]@1
  char v30; // [sp+80h] [bp-218h]@6
  char v31; // [sp+100h] [bp-198h]@6
  char v32; // [sp+180h] [bp-118h]@1
  char v33; // [sp+200h] [bp-98h]@1

  printf("<form method=post action=timepro.cgi name=email_fm style=\"padding:0; margin:0;\">");
  puts("<input type=hidden name=tmenu value=sysconf>");
  puts("<input type=hidden name=smenu value=login>");
  puts("<input type=hidden name=act value=>");
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"100\"><COL width=\"145\"><COL width=\"152\"><COL width=\"145\"><COL width=\"70\"><COL width=\"30\">");
  printf("<tr class=\"login_main_tr\" height=\"24\" style=\"background-color:#E3E3E3; border-top:1px #CCC solid; border-bottom:1px #CCC solid;\">\t\t<td class=\"login_main_td\" colspan=\"4\">");
  v1 = sub_134F4(933, v0);
  printf("<p class=\"login_main_p\"><b>%s</b></p>", v1);
  v2 = printf("</td><td class=\"login_main_td\" align=\"right\">");
  v3 = sub_126C4(v2);
  v5 = sub_134F4(118, v4);
  printf(
    "<span class=\"login_main_span\" onclick=\"DeleteEmailConfig();\" style=\"width:55px; cursor:pointer;\">\t\t<img src="
    "\"/%s/minus_icon.gif\" style=\"margin-right:5px;\">%s</span>",
    v3,
    v5);
  printf("</td><td class=\"login_main_td\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\"><td class=\"login_main_td\" colspan=\"6\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v7 = sub_134F4(932, v6);
  printf("<p class=\"login_main_p\">%s</p>", v7);
  printf("</td><td class=\"login_main_td\">");
  get_admin_email(&v33);
  printf("<input type=text name=email style=\"width:140px;\" maxlength=120 value=%s>", &v33);
  printf("</td><td class=\"login_main_td\" align=\"right\">");
  v9 = sub_134F4(944, v8);
  printf("<span class=\"login_main_span\" style=\"margin-right:10px;\">%s</span>", v9);
  printf("</td><td class=\"login_main_td\">");
  get_smtp_server(&v32);
  printf("<input type=text name=smtp style=\"width:140px;\" maxlength=120 value=%s>", &v32);
  printf("</td><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v11 = sub_134F4(940, v10);
  v12 = "checked";
  printf("<p class=\"login_main_p\">%s</p>", v11);
  printf("</td><td class=\"login_main_td\">");
  get_send_email(&v29);
  printf("<input type=text name=send_email style=\"width:140px;\" maxlength=120 value=%s>", &v29);
  printf("</td><td class=\"login_main_td\" colspan=\"4\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v14 = sub_134F4(945, v13);
  printf("<p class=\"login_main_p\">%s</p>", v14);
  printf("</td><td class=\"login_main_td\" colspan=\"5\">");
  v15 = printf("<span class=\"login_main_span\">");
  if ( get_smtp_auth(v15) )
    v17 = "checked";
  else
    v17 = "";
  v18 = sub_134F4(947, v16);
  printf(
    "<input type=radio id=\"smtptrue\" name=smtp_auth %s value=on onclick=\"ChangeAuth();\"><label for=\"smtptrue\">%s</label>",
    v17,
    v18);
  v19 = printf("</span><span class=\"login_main_span\" style=\"margin-left:15px;\">");
  if ( get_smtp_auth(v19) )
    v12 = "";
  v21 = sub_134F4(946, v20);
  printf(
    "<input type=radio id=\"smtpfalse\" name=smtp_auth %s value=off onclick=\"ChangeAuth();\"><label for=\"smtpfalse\">%s</label>",
    v12,
    v21);
  printf("</span>");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v23 = sub_134F4(942, v22);
  printf("<p class=\"login_main_p\">%s</p>", v23);
  printf("</td><td class=\"login_main_td\" colspan=\"3\">");
  get_smtp_account(&v31);
  printf("<input type=text name=account style=\"width:140px;\" maxlength=120 value=\"%s\">", &v31);
  v25 = sub_134F4(943, v24);
  printf("<span class=\"login_main_span\" style=\"margin:0 5px 0 15px;\">%s</span>", v25);
  get_smtp_password(&v30);
  printf("<input type=password name=smtp_pass style=\"width:140px;\" maxlength=120 value=\"");
  sub_11658(&v30);
  printf("\">");
  printf("</td><td class=\"login_main_td\" align=\"right\">");
  printf("<button class=\"login_main_button\" style=\"width:55px;\" onclick=\"ChangeEmailConfig(); return ClickEventPropagater(event);\">");
  v27 = sub_134F4(28, v26);
  printf("<span class=\"login_main_span\">%s</span>", v27);
  printf("</button>");
  printf("</td><td class=\"login_main_td\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\" style=\"border-bottom:1px #CCC solid;\"><td class=\"login_main_td\" colspan=\"6\">");
  printf("</td></tr>");
  printf("</table>");
  printf("</form>");
  puts("<script language=JavaScript>");
  puts("ChangeAuth();");
  return printf("</script>");
}


int sub_195E4()
{
  int v0; // r10@1
  signed int v1; // r4@2
  int v2; // r1@4
  int v3; // r0@4
  char *v4; // r5@4
  char *v5; // r8@4
  int v6; // r1@4
  char *v7; // r4@5
  int v8; // r0@7
  int v9; // r1@7
  int v10; // r0@7
  int v11; // r1@7
  int v12; // r0@9
  int v13; // r0@9
  int v14; // r4@9
  int v15; // r1@9
  int v16; // r5@9
  int v17; // r0@9
  int v18; // r1@9
  int v19; // r0@9
  int v20; // r1@9
  char *v21; // r4@10
  int v22; // r0@12
  int v23; // r1@12
  char *v24; // r4@13
  int v25; // r0@15
  int v26; // r1@15
  int v27; // r0@17
  int v28; // r0@17
  int v29; // r0@17
  int v30; // r1@17
  int v31; // r0@17
  int v32; // r1@17
  int v33; // r0@17
  int v34; // r0@17
  int v35; // r1@18
  int v36; // r0@18
  char v38; // [sp+0h] [bp-100h]@1
  char dest; // [sp+80h] [bp-80h]@1
  char v40; // [sp+C0h] [bp-40h]@4

  v0 = get_captcha_usage_type();
  strcpy(&dest, "");
  strcpy(&v38, "");
  get_id_password(&dest, &v38);
  if ( dest )
    v1 = v38 == 0;
  else
    v1 = 1;
  printf("<form method=post action=timepro.cgi name=session_fm style=\"padding:0; margin:0;\">");
  puts("<input type=hidden name=tmenu value=sysconf>");
  puts("<input type=hidden name=smenu value=login>");
  puts("<input type=hidden name=act value=>");
  printf("<input type=hidden name=noid value=%d>\n", v1);
  get_http_auth_method(&v40);
  printf("<input type=hidden name=prev_auth_method value=%s>\n", &v40);
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"100\"><COL width=\"450\"><COL width=\"62\"><COL width=\"30\">");
  printf("<tr class=\"login_main_tr\" height=\"24\" style=\"background-color:#E3E3E3; border-top:1px #CCC solid; border-bottom:1px #CCC solid;\">\t\t<td class=\"login_main_td\" colspan=\"4\">");
  v3 = sub_134F4(969, v2);
  v4 = "checked";
  v5 = "selected";
  printf("<p class=\"login_main_p\"><b>%s</b></p>", v3);
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  if ( !strcmp(&v40, "basic") )
    v7 = "checked";
  else
    v7 = "";
  v8 = sub_134F4(494, v6);
  printf(
    "<input type=radio id=\"authh\" name=http_auth value=basic %s onclick=\"InitLogin();\"><label for=\"authh\">%s</label>",
    v7,
    v8);
  printf("</td><td class=\"login_main_td\">");
  v10 = sub_134F4(929, v9);
  printf("<span class=\"login_main_span\">%s</span>", v10);
  printf("</td><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  if ( !strcmp(&v40, "basic") )
    v4 = "";
  v12 = sub_134F4(506, v11);
  printf(
    "<input type=radio id=\"auths\" name=http_auth value=session %s onclick=\"InitLogin();\"><label for=\"auths\">%s</label>",
    v4,
    v12);
  v13 = printf("</td><td class=\"login_main_td\" colspan=3>");
  v14 = httpcon_get_session_timeout(v13);
  v16 = sub_134F4(119, v15);
  v17 = sub_43AF4(v14, 60);
  printf(
    "<input type=text name=http_session_timeout value=%d size=3 maxlength=3 style='text-align: center;'> %s\n",
    v17,
    v16);
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  printf("</td><td class=\"login_main_td\">");
  v19 = sub_134F4(1145, v18);
  printf("%s", v19);
  printf("<select name='use_captcha' onchange='onChangeCaptchaUsage();' style='margin-left: 10px; height: 20px; border: 1px solid #CCC;'>");
  if ( v0 )
    v21 = "";
  else
    v21 = "selected";
  v22 = sub_134F4(1144, v20);
  printf("<option value='off' %s>%s</option>", v21, v22);
  if ( v0 == 1 )
    v24 = "selected";
  else
    v24 = "";
  v25 = sub_134F4(1140, v23);
  printf("<option value='always' %s>%s</option>", v24, v25);
  if ( v0 != 2 )
    v5 = "";
  v27 = sub_134F4(1143, v26);
  printf("<option value='manual' %s>%s</option>", v5, v27);
  v28 = printf("</select>");
  v29 = get_client_login_trial_count_without_captchar(v28);
  printf(
    "<input type='number' name='captcha_attempt' min=0 value=%d  style='width: 35px; text-align: center;margin: 0 5px; bo"
    "rder: 1px solid #CCC;'>",
    v29);
  v31 = sub_134F4(1141, v30);
  printf("<p id='captcha_desc' style='display: inline;'>%s</p>", v31);
  printf("</td><td class=\"login_main_td\" align=\"right\">");
  printf("<button class=\"login_main_button\" style=\"width:55px;\" onclick=\"ApplySession(); return ClickEventPropagater(event);\">");
  v33 = sub_134F4(28, v32);
  printf("<span class=\"login_main_span\">%s</span>", v33);
  printf("</button>");
  printf("</td><td class=\"login_main_td\">");
  v34 = printf("</td></tr>");
  if ( check_default_pass(v34) )
  {
    printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
    printf("</td><td class=\"login_main_td\" colspan=3>");
    v36 = sub_134F4(1142, v35);
    printf("<span id='captcha_warning' style='color:gray;'>%s</span>", v36);
    printf("</td></tr>");
  }
  printf("</table>");
  printf("</form>");
  puts("<script language=JavaScript>");
  puts("InitLogin();");
  return printf("</script>");
}

int sub_199C0()
{
  int v0; // r1@1
  int v1; // r0@1
  int v2; // r1@1
  int v3; // r0@1
  int v4; // r1@1
  char *v5; // r0@2
  int v6; // r1@4
  int v7; // r0@4
  int v8; // r1@4
  int v9; // r0@5
  int v10; // r0@7
  int v11; // r1@7
  int v12; // r0@7
  int v13; // r1@7
  int v14; // r0@7
  int v15; // r1@7
  int v16; // r0@7
  int v17; // r1@7
  int v18; // r0@7
  int v19; // r1@7
  int v20; // r0@7
  int v21; // r1@7
  int v22; // r0@7
  int v23; // r1@7
  int v24; // r0@7
  int v26; // [sp+0h] [bp-1D0h]@1
  char v27; // [sp+80h] [bp-150h]@1
  char v28; // [sp+100h] [bp-D0h]@1
  char v29; // [sp+140h] [bp-90h]@1
  char v30; // [sp+180h] [bp-50h]@7
  char v31; // [sp+1A0h] [bp-30h]@7

  get_id_password(&v29, &v27);
  get_default_id_password(&v28, &v26);
  printf("<form method=post action=timepro.cgi name=login_fm style=\"padding:0; margin:0;\">");
  puts("<input type=hidden name=tmenu value=sysconf>");
  puts("<input type=hidden name=smenu value=login>");
  puts("<input type=hidden name=act value=>");
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"321\"><COL width=\"321\">");
  printf("<tr class=\"login_main_tr\" height=\"24\" style=\"background-color:#E3E3E3; border-top:1px #CCC solid; border-bottom:1px #CCC solid;\">\t\t<td class=\"login_main_td\" colspan=\"2\">");
  v1 = sub_134F4(941, v0);
  printf("<p class=\"login_main_p\"><b>%s</b></p>", v1);
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\" style=\"background-color:#FFFFFF;\"><td class=\"login_main_td\" colspan=\"2\">");
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"120\"><COL width=\"170\"><COL width=\"80\"><COL width=\"272\">");
  printf("<tr class=\"login_main_tr\" height=\"24\" style=\"background-color:#FFFFFF;\"><td class=\"login_main_td\">");
  v3 = sub_134F4(930, v2);
  printf("<p class=\"login_main_p\"><b>%s</b></p>", v3);
  printf("</td><td class=\"login_main_td\">");
  if ( v29 )
    v5 = &v29;
  else
    v5 = (char *)sub_134F4(937, v4);
  printf("<span class=\"login_main_span\">%s</span>", v5);
  printf("</td><td class=\"login_main_td\">");
  v7 = sub_134F4(931, v6);
  printf("<p class=\"login_main_p\"><b>%s</b></p>", v7);
  printf("</td><td class=\"login_main_td\">");
  if ( v27 )
    v9 = 938;
  else
    v9 = 937;
  v10 = sub_134F4(v9, v8);
  printf("<span class=\"login_main_span\">%s</span>", v10);
  printf("</td></tr>");
  printf("</table>");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\"><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"72\"><td class=\"login_main_td\">");
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"100\"><COL width=\"145\"><COL width=\"76\">");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v12 = sub_134F4(935, v11);
  printf("<p class=\"login_main_p\">%s</p>", v12);
  printf("</td><td class=\"login_main_td\">");
  puts("<input type=text name=new_login maxlength=32 style=\"width:140px\" value=>");
  printf("</td><td class=\"login_main_td\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v14 = sub_134F4(936, v13);
  printf("<p class=\"login_main_p\">%s</p>", v14);
  printf("</td><td class=\"login_main_td\">");
  printf("<input type=password name=new_passwd style=\"width:140px\" maxlength=32 value=>");
  printf("<input type=text name=new_passwd_text style=\"display:none; ime-mode:disabled; width:140px;\" maxlength=32 value=>");
  printf("</td><td class=\"login_main_td\">");
  printf("<input type=checkbox id=passview NAME=password_view value=1 onclick=\"PasswordView(new_passwd,new_passwd_text,password_view);\" >");
  v16 = sub_134F4(1148, v15);
  printf("<label for=\"passview\">%s</label>", v16);
  printf("</td></tr>");
  v18 = sub_134F4(939, v17);
  printf("<input type=hidden name=default_captcha_desc value='%s'>\n", v18);
  puts("<input type=hidden name=captcha_file value=>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  v20 = sub_134F4(970, v19);
  printf("<p class=\"login_main_p\">%s</p>", v20);
  printf("</td><td class=\"login_main_td\" colspan=\"2\">");
  v22 = sub_134F4(939, v21);
  printf(
    "<input type=text name=captcha_code maxlength=\"5\" STYLE=\"width:205px; color:#888888;\" value=\"%s\"         \tonfo"
    "cus=\"FocusCaptcha(document.login_fm);\" onblur=\"BlurCaptcha(document.login_fm);\">",
    v22);
  printf("</td></tr>");
  printf("</table>");
  printf("</td><td class=\"login_main_td\">");
  get_http_auth_method(&v30);
  get_ux_lang(&v31);
  puts("<table class=\"v3_table login_main_table\" width=\"321\" height=\"72\">");
  printf("<COL width=\"291\"><COL width=\"30\">");
  printf("<tr class=\"login_main_tr\"><td class=\"login_main_td\">");
  puts("<table class=\"v3_table login_main_table\" width=\"254\" height=\"72\">");
  printf("<COL width=\"90\"><COL width=\"201\">");
  printf(
    "<tr class=\"login_main_tr\" \t\tstyle=\"font: normal normal normal 12px arial; color:#000000; border:#C6C9CC 1px sol"
    "id; background-color:#FFFFFF;\" height=\"72\">\t\t<td class=\"login_main_td\" style=\"cursor:pointer; background-col"
    "or:#FAFAFA; border:0;\" \t\tonclick=\"iframe_captcha.location.reload();\">\t\t<img src=\"/images2/captcha_noborder.%"
    "s.gif\" style=\"border:0; margin-left:18px;\"></td>\n",
    &v31);
  strcmp(&v30, "session");
  printf("<td class=\"login_main_td\" style=\"border-left:1px #CCC solid;\">\t\t<iframe name=iframe_captcha id=iframe_captcha src=\"/%s/captcha.cgi\" width=\"200\" height=\"72\" \t\tframeborder=no scrolling=no></iframe>\t\t</td></tr>\n");
  printf("</table>");
  printf("</td><td class=\"login_main_td\"></td></tr></table>");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\"><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\" style=\"border-top:1px #CCC solid;\"><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"24\"><td class=\"login_main_td\">");
  printf("</td><td class=\"login_main_td\" align=\"right\" style=\"padding-right:30px;\">");
  printf("<button class=\"login_main_button\" style=\"width:90px;\" onclick=\"ApplyLogin(); return ClickEventPropagater(event);\">");
  v24 = sub_134F4(934, v23);
  printf("<span class=\"login_main_span\">%s</span>", v24);
  printf("</button>");
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\" height=\"5\"><td class=\"login_main_td\" colspan=\"2\">");
  printf("</td></tr>");
  printf("</table>");
  return printf("</form>");
}


int sub_19E0C()
{
  int v0; // r0@1
  int v1; // r0@2
  int v2; // r0@4
  int v3; // r0@4
  int v4; // r0@4
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@4

  sub_133E4("sysconf", "login");
  puts("<style type=\"text/css\">");
  puts(".login_main_table {");
  puts("\tborder-collapse:collapse; padding:0 0 0 0; margin:0 0 0 0;");
  puts("\ttable-layout:fixed;");
  puts("}");
  puts(".login_main_tr {");
  puts("\tborder:0 0 0 0; padding:0 0 0 0;");
  puts("}");
  puts(".login_main_td {");
  puts("\tpadding:0 0 0 0; font-size:12px;");
  puts("\tvertical-align:middle;");
  puts("}");
  puts(".login_main_p {");
  puts("\tpadding:0 0 0 5px; display:inline-block;");
  puts("\tvertical-align:middle; margin:0;");
  puts("}");
  puts(".login_main_span {");
  puts("\tdisplay:inline-block; vertical-align:middle;");
  puts("}");
  puts(".login_main_button {");
  puts("\tpadding:0 1 0 1; margin:0 0 0 0; font-size:12px;");
  puts("\tvertical-align:middle;");
  puts("}");
  puts(".login_main_td input[type=checkbox], .login_main_td input[type=radio] {");
  puts("display:inline-block; vertical-align:middle;");
  puts("}");
  puts("#login_div_msg p {");
  puts("margin:5 0 5 15px; text-align:left;");
  puts("}");
  puts(".login_ellipsis {");
  puts("text-overflow:ellipsis; overflow:hidden; white-space:nowrap; text-align:left;");
  puts("}");
  printf("input[type=\"text\"] {border:1px #CCC solid;}");
  printf("input[type=\"password\"] {border:1px #CCC solid;}");
  printf("input[type=\"checkbox\"], input[type=\"radio\"], label, span, td {cursor:default;}");
  printf("</style>");
  printf("<table class=\"v3_table login_main_table\" width=\"100%%\" style=\"padding:0; margin:0;\">\n");
  printf("<COL width=\"642\">");
  printf("<tr class=\"login_main_tr\"><td class=\"login_main_td\">");
  sub_199C0();
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\"><td class=\"login_main_td\">");
  sub_195E4();
  printf("</td></tr>");
  printf("<tr class=\"login_main_tr\"><td class=\"login_main_td\">");
  sub_1922C();
  v0 = printf("</td></tr>");
  if ( is_mobile_agent(v0) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    v1 = printf("<iframe name=\"hiddenloginsetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenloginsetup\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
    sub_12770(v1);
  }
  else
  {
    printf("<iframe name=\"hiddenloginsetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenloginsetup\"                         frameborder=no width=0 height=0 align=center scrolling=no></iframe>");
  }
  printf("</table>");
  printf("<DIV id=\"%s\" style=\"display:none;\">", "apply_mask");
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:535px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:231px; top:198px; width:180px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"180\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v2 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v3 = sub_126C4(v2);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v3);
  printf("</SPAN></td>");
  printf("<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\" id=\"login_div_msg\">\n");
  printf("</SPAN></td>");
  printf((const char *)&unk_60F0E);
  printf("<DIV id=\"relogin_mask\" style=\"display:none;\">");
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:535px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:171px; top:198px; width:300px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"300\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v4 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v5 = sub_126C4(v4);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v5);
  printf("</SPAN></td>");
  v7 = sub_134F4(505, v6);
  printf(
    "<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:"
    "middle; display:block; text-align:center;\">%s",
    v7);
  printf("</SPAN></td>");
  return printf((const char *)&unk_60F0E);
}


int __fastcall sub_1A180(int a1, int a2, int a3)
{
  int v3; // r6@1
  int v4; // r7@1
  int v5; // r5@1

  v3 = a2;
  v4 = a3;
  v5 = a1;
  printf("<TR height=20 ID=%s STYLE=\"cursor:pointer; background-color:#%s;\" ONCLICK=\"clickSysconf(this);\">", a1);
  return printf("<TD></TD><TD>%s</TD><TD CLASS=text_gray ID=%s_value >%s</TD><TD>%s</TD></TR>\n", v3, v5, v4);
}


int sub_1A1E0()
{
  printf("<TR height=20 STYLE=\"background-Color:#%s\">");
  return printf("<TD></TD><TD></TD><TD CLASS=text_gray></TD><TD></TD></TR>");
}


int __fastcall sub_1A218(int a1, int a2, int a3)
{
  char *v3; // r2@2
  int v4; // r4@4
  int v5; // r1@5

  if ( a3 )
    v3 = "disabled";
  else
    v3 = "";
  printf("<select name=%s %s>", a1, v3);
  v4 = 0;
  do
  {
    v5 = v4++;
    printf("<option value=%d %s>%d", v5);
  }
  while ( v4 != 60 );
  return printf("</select>");
}


int __fastcall sub_1A294(int a1, int a2, int a3)
{
  char *v3; // r2@2
  int v4; // r4@4
  int v5; // r1@5

  if ( a3 )
    v3 = "disabled";
  else
    v3 = "";
  printf("<select name=%s %s>", a1, v3);
  v4 = 0;
  do
  {
    v5 = v4++;
    printf("<option value=%d %s >%d", v5);
  }
  while ( v4 != 24 );
  return printf("</select>");
}


int sub_1A310()
{
  int v0; // r1@1
  int v1; // r0@1

  printf("<table CELLPADDING=0 CELLSPACING=0><tr height=23px><td style=\"padding-left:5px;\">");
  v1 = sub_134F4(922, v0);
  printf("%s", v1);
  printf("</td>");
  return printf("</tr></table>");
}


int __fastcall sub_1A358(const char *a1, int a2)
{
  int v2; // r5@1
  const char *v3; // r4@1
  int v4; // r0@3
  int v5; // r0@3

  v2 = a2;
  v3 = a1;
  if ( !strcmp(a1, "reboot_mask") )
  {
    printf("<style>");
    printf("#%s p { margin: 5px 0 5px 15px; text-align: left; }", v3);
    printf("</style>");
  }
  printf("<DIV id=\"%s\" style=\"display:none;\">", v3);
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:535px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:231px; top:198px; width:180px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"180\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v4 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v5 = sub_126C4(v4);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v5);
  printf("</SPAN></td>");
  printf(
    "<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:"
    "middle; display:block; text-align:center;\">%s\n",
    v2);
  printf("</SPAN></td>");
  return printf((const char *)&unk_60F0E);
}


void *__fastcall sub_1A440(const char *a1)
{
  const char *v1; // r4@1
  int v2; // r1@1
  int v3; // r0@2
  const char *v4; // r1@11
  char *v5; // r0@11

  v1 = a1;
  if ( !strcmp(a1, "auto") )
  {
    v3 = 540;
  }
  else if ( !strcmp(v1, "kr") )
  {
    v3 = 111;
  }
  else if ( !strcmp(v1, "en") )
  {
    v3 = 110;
  }
  else if ( !strcmp(v1, "ch") )
  {
    v3 = 108;
  }
  else
  {
    if ( strcmp(v1, "cx") )
    {
      v5 = (char *)&unk_98520;
      v4 = "";
      goto LABEL_13;
    }
    v3 = 109;
  }
  v4 = (const char *)sub_134F4(v3, v2);
  v5 = (char *)&unk_98520;
LABEL_13:
  strcpy(v5, v4);
  return &unk_98520;
}


char *__fastcall sub_1A4FC(char *result, const char *a2, const char *a3, char a4, int a5)
{
  char *v5; // r6@1
  const char *v6; // r7@1
  char v7; // r8@1
  char *v8; // r4@2

  v5 = result;
  v6 = a3;
  v7 = a4;
  if ( (signed int)result <= 27 )
  {
    v8 = &byte_987C0[144 * (_DWORD)result];
    strcpy(&byte_987C0[144 * (_DWORD)result], a2);
    result = strcpy(&byte_987C0[8 * (18 * (_DWORD)v5 + 1)], v6);
    *((_DWORD *)v8 + 35) = a5;
    v8[136] = v7;
  }
  return result;
}


char *__fastcall sub_1A554(int a1, int a2)
{
  const char *v2; // r0@1
  int v3; // r1@1
  const char *v4; // r0@1
  int v5; // r1@1
  const char *v6; // r0@1
  int v7; // r1@1
  const char *v8; // r0@1
  int v9; // r1@1
  const char *v10; // r0@1
  int v11; // r1@1
  const char *v12; // r0@1
  int v13; // r1@1
  const char *v14; // r0@1
  int v15; // r1@1
  const char *v16; // r0@1
  int v17; // r1@1
  const char *v18; // r0@1
  int v19; // r1@1
  const char *v20; // r0@1
  int v21; // r1@1
  const char *v22; // r0@1
  int v23; // r1@1
  const char *v24; // r0@1
  int v25; // r1@1
  const char *v26; // r0@1
  int v27; // r1@1
  const char *v28; // r0@1
  int v29; // r1@1
  const char *v30; // r0@1
  int v31; // r1@1
  const char *v32; // r0@1
  int v33; // r1@1
  const char *v34; // r0@1
  int v35; // r1@1
  const char *v36; // r0@1
  int v37; // r1@1
  const char *v38; // r0@1
  int v39; // r1@1
  const char *v40; // r0@1
  int v41; // r1@1
  const char *v42; // r0@1
  int v43; // r1@1
  const char *v44; // r0@1
  int v45; // r1@1
  const char *v46; // r0@1
  int v47; // r1@1
  const char *v48; // r0@1
  int v49; // r1@1
  const char *v50; // r0@1
  int v51; // r1@1
  const char *v52; // r0@1
  int v53; // r1@1
  const char *v54; // r0@1
  int v55; // r1@1
  const char *v56; // r0@1

  v2 = (const char *)sub_134F4(348, a2);
  sub_1A4FC(0, "gmt0", v2, 45, 720);
  v4 = (const char *)sub_134F4(359, v3);
  sub_1A4FC((char *)1, "gmt1", v4, 45, 660);
  v6 = (const char *)sub_134F4(368, v5);
  sub_1A4FC((char *)2, "gmt2", v6, 45, 600);
  v8 = (const char *)sub_134F4(369, v7);
  sub_1A4FC((char *)3, "gmt3", v8, 45, 540);
  v10 = (const char *)sub_134F4(370, v9);
  sub_1A4FC((char *)4, "gmt4", v10, 45, 480);
  v12 = (const char *)sub_134F4(371, v11);
  sub_1A4FC((char *)5, "gmt5", v12, 45, 420);
  v14 = (const char *)sub_134F4(372, v13);
  sub_1A4FC((char *)6, "gmt6", v14, 45, 360);
  v16 = (const char *)sub_134F4(373, v15);
  sub_1A4FC((char *)7, "gmt7", v16, 45, 300);
  v18 = (const char *)sub_134F4(374, v17);
  sub_1A4FC((char *)8, "gmt8", v18, 45, 240);
  v20 = (const char *)sub_134F4(375, v19);
  sub_1A4FC((char *)9, "gmt9", v20, 45, 180);
  v22 = (const char *)sub_134F4(349, v21);
  sub_1A4FC((char *)0xA, "gmt10", v22, 45, 120);
  v24 = (const char *)sub_134F4(350, v23);
  sub_1A4FC((char *)0xB, "gmt11", v24, 45, 60);
  v26 = (const char *)sub_134F4(351, v25);
  sub_1A4FC((char *)0xC, "gmt12", v26, 43, 0);
  v28 = (const char *)sub_134F4(352, v27);
  sub_1A4FC((char *)0xD, "gmt13", v28, 43, 60);
  v30 = (const char *)sub_134F4(353, v29);
  sub_1A4FC((char *)0xE, "gmt14", v30, 43, 120);
  v32 = (const char *)sub_134F4(354, v31);
  sub_1A4FC((char *)0xF, "gmt15", v32, 43, 180);
  v34 = (const char *)sub_134F4(355, v33);
  sub_1A4FC((char *)0x10, "gmt16", v34, 43, 210);
  v36 = (const char *)sub_134F4(356, v35);
  sub_1A4FC((char *)0x11, "gmt17", v36, 43, 240);
  v38 = (const char *)sub_134F4(357, v37);
  sub_1A4FC((char *)0x12, "gmt18", v38, 43, 300);
  v40 = (const char *)sub_134F4(358, v39);
  sub_1A4FC((char *)0x13, "gmt19", v40, 43, 330);
  v42 = (const char *)sub_134F4(360, v41);
  sub_1A4FC((char *)0x14, "gmt20", v42, 43, 360);
  v44 = (const char *)sub_134F4(361, v43);
  sub_1A4FC((char *)0x15, "gmt21", v44, 43, 420);
  v46 = (const char *)sub_134F4(362, v45);
  sub_1A4FC((char *)0x16, "gmt22", v46, 43, 480);
  v48 = (const char *)sub_134F4(363, v47);
  sub_1A4FC((char *)0x17, "gmt23", v48, 43, 540);
  v50 = (const char *)sub_134F4(364, v49);
  sub_1A4FC((char *)0x18, "gmt24", v50, 43, 600);
  v52 = (const char *)sub_134F4(365, v51);
  sub_1A4FC((char *)0x19, "gmt25", v52, 43, 660);
  v54 = (const char *)sub_134F4(366, v53);
  sub_1A4FC((char *)0x1A, "gmt26", v54, 43, 720);
  v56 = (const char *)sub_134F4(367, v55);
  return sub_1A4FC((char *)0x1B, "gmt27", v56, 43, 780);
}


int sub_1A9F4()
{
  char v1; // [sp+1h] [bp-107h]@1

  get_hostname(&v1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td colspan=4 style=\"padding-left:5px;\">");
  printf("<input type=text name=hostname  size=60 maxlength=60 value='%s'>", &v1);
  printf("</td></tr>");
  return printf("</TABLE>");
}


int sub_1AA50()
{
  int v1; // [sp+0h] [bp-108h]@1

  printf("<script>");
  sub_130BC(&v1, 256);
  printf("setTimeout(function() { ");
  printf("parent.document.getElementById('current_time').outerHTML = \"<span id='current_time'>%s</span>\";", &v1);
  printf(
    "parent.document.getElementsByName('sysconf_misc_iframe')[0].contentWindow.document.getElementById('realtime_value')."
    "outerHTML = '<TD CLASS=text_gray ID=realtime_value >%s</TD>';",
    &v1);
  printf("}, 500);");
  printf("setTimeout(function() { location.reload(); }, 3000);");
  return printf("</script>");
}


char *sub_1AACC()
{
  char *result; // r0@2
  char v1; // [sp+4h] [bp-5Ch]@1

  get_timeserver_conf(&v1);
  if ( !strcmp(&v1, "null") )
  {
    result = "";
  }
  else
  {
    strcpy((char *)&unk_98560, &v1);
    result = (char *)&unk_98560;
  }
  return result;
}



int sub_1AB1C()
{
  char *v0; // r5@1
  int v1; // r7@1
  int v2; // r1@1
  char *v3; // r4@2
  int v4; // r0@4
  int v5; // r1@4
  int v6; // r0@6

  v0 = "checked";
  v1 = get_nologin();
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td style=\"padding-left:5px;\" colspan=4>");
  if ( v1 )
    v3 = "";
  else
    v3 = "checked";
  v4 = sub_134F4(955, v2);
  printf("<input type=radio id=nologin_off name=nologin value=0 %s ><label for=nologin_off> %s</label>", v3, v4);
  printf("</td></tr><tr height=23px><td style=\"padding-left:5px;\"colspan=4 >");
  if ( !v1 )
    v0 = "";
  v6 = sub_134F4(956, v5);
  printf("<input type=radio id=nologin_on name=nologin value=1 %s ><label for=nologin_on> %s</label>", v0, v6);
  printf("</td></tr>");
  return printf("</TABLE>");
}



int sub_1ABC8()
{
  FILE *v0; // r10@1
  int v1; // r7@2
  char *v2; // r0@4
  const char *v3; // r4@5
  char *v4; // r6@5
  const char *v5; // r6@6
  unsigned __int16 v6; // r11@6
  char *v7; // r0@6
  const char *v8; // r4@7
  char *v9; // r5@7
  const char *v10; // r5@8
  unsigned __int16 v11; // r4@8
  int v12; // r5@11
  int v13; // r4@11
  bool v14; // nf@13
  unsigned __int8 v15; // vf@13
  int v17; // [sp+0h] [bp-A8h]@4

  printf("<html><head></head><body width=100%% bottommargin=0 rightmargin=0 leftmargin=0 topmargin=0 marginheight=0 >");
  printf("<form method=post action=\"timepro.cgi\" name=\"upnp_list_fm\">");
  printf("<input type=hidden name=\"tmenu\" value=\"popup\">");
  printf("<input type=hidden name=\"smenu\" value=\"upnp_list\">");
  printf("<table cellspacing=0px cellpadding=0px border=0 width=100%% align=left>");
  v0 = fopen("/var/run/upnp_pmlist", "r");
  if ( v0 )
  {
    v1 = 0;
    while ( fgets((char *)&v17, 128, v0) )
    {
      v2 = strchr((const char *)&v17, 59);
      ++v1;
      if ( v2 )
      {
        *v2 = 0;
        v3 = v2 + 1;
        v4 = strchr(v2 + 1, 59);
        if ( v4 )
        {
          *v4 = 0;
          v5 = v4 + 1;
          v6 = atoi(v3);
          v7 = strchr(v5, 59);
          if ( v7 )
          {
            *v7 = 0;
            v8 = v7 + 1;
            v9 = strchr(v7 + 1, 59);
            if ( v9 )
            {
              *v9 = 0;
              v10 = v9 + 1;
              v11 = atoi(v8);
              *strchr(v10, 10) = 0;
              printf("<tr style=\"background:#%s;height:20px;\">");
              printf("<td width=72px style=\"padding-left:5px;\">%s</td>\n", &v17);
              printf("<td width=76px>%d</td>\n", v6);
              printf("<td width=146px>%s:%d</td>\n", v5, v11);
              printf("<td width=318px>%s</td>\n", v10);
              printf("</tr>");
            }
          }
        }
      }
    }
    fclose(v0);
  }
  else
  {
    v1 = 0;
  }
  v12 = 5 - v1;
  v13 = 0;
  while ( 1 )
  {
    v15 = __OFSUB__(v13, v12);
    v14 = v13++ - v12 < 0;
    if ( !(v14 ^ v15) )
      break;
    sub_1A1E0();
  }
  printf("</table>");
  printf("</form>");
  return printf((const char *)&unk_619C3);
}


signed int __fastcall sub_1ADC0(int a1)
{
  int v1; // r6@1
  _BYTE *v2; // r0@5
  int v3; // r0@7
  int v4; // r4@10
  int v5; // r4@14
  const char *v6; // r1@15
  int v7; // r0@17
  int *v8; // r0@21
  signed int v9; // r1@21
  int v10; // r0@26
  int v11; // r0@29
  int v12; // r0@32
  int v13; // r4@37
  int v14; // r0@37
  bool v15; // zf@37
  signed int v16; // r3@40
  int v17; // r12@43
  int v18; // r4@46
  int v19; // r3@46
  int v20; // r4@51
  int v21; // r3@51
  int v22; // r4@56
  int v23; // r3@56
  int v24; // r4@61
  int v25; // r3@61
  int v26; // r4@66
  int v27; // r3@66
  int v28; // r4@71
  int v29; // r3@71
  int v30; // r4@76
  int v31; // r3@76
  const char *v32; // r1@90
  signed int v33; // r0@90
  int v34; // r0@93
  int v35; // r0@94
  int v36; // r0@102
  int v38; // r0@130
  int v39; // r0@132
  int v40; // r0@133
  int v41; // r1@133
  int v42; // r0@134
  int v43; // [sp+0h] [bp-950h]@100
  int v44; // [sp+10h] [bp-940h]@100
  int v45; // [sp+24h] [bp-92Ch]@100
  char v46; // [sp+38h] [bp-918h]@100
  int v47; // [sp+4Ch] [bp-904h]@100
  int v48; // [sp+60h] [bp-8F0h]@100
  int v49; // [sp+3B8h] [bp-598h]@106
  int v50; // [sp+3BCh] [bp-594h]@106
  int v51; // [sp+3C0h] [bp-590h]@108
  int v52; // [sp+440h] [bp-510h]@111
  int v53; // [sp+4C0h] [bp-490h]@114
  char dest; // [sp+540h] [bp-410h]@117
  char v55; // [sp+5C0h] [bp-390h]@120
  _BYTE v56[3]; // [sp+641h] [bp-30Fh]@3
  char v57; // [sp+740h] [bp-210h]@105
  char s; // [sp+7C0h] [bp-190h]@124
  char v59; // [sp+800h] [bp-150h]@130
  int v60; // [sp+808h] [bp-148h]@130
  int v61; // [sp+80Ch] [bp-144h]@130
  int v62; // [sp+810h] [bp-140h]@128
  int v63; // [sp+814h] [bp-13Ch]@37
  int v64; // [sp+834h] [bp-11Ch]@46
  int v65; // [sp+838h] [bp-118h]@45
  char v66; // [sp+83Ch] [bp-114h]@49
  char v67; // [sp+83Dh] [bp-113h]@54
  char v68; // [sp+83Eh] [bp-112h]@59
  char v69; // [sp+83Fh] [bp-111h]@64
  char v70; // [sp+840h] [bp-110h]@69
  char v71; // [sp+841h] [bp-10Fh]@74
  char v72; // [sp+842h] [bp-10Eh]@79
  int v73; // [sp+844h] [bp-10Ch]@81
  int v74; // [sp+848h] [bp-108h]@82
  int v75; // [sp+84Ch] [bp-104h]@84
  int v76; // [sp+850h] [bp-100h]@82
  int v77; // [sp+854h] [bp-FCh]@84
  int v78; // [sp+858h] [bp-F8h]@1
  int v79; // [sp+898h] [bp-B8h]@96
  int v80; // [sp+8B8h] [bp-98h]@96
  int v81; // [sp+8CCh] [bp-84h]@96
  char v82; // [sp+8E0h] [bp-70h]@98
  int v83; // [sp+8F4h] [bp-5Ch]@98
  int v84; // [sp+908h] [bp-48h]@97
  int v85; // [sp+91Ch] [bp-34h]@20
  int v86; // [sp+92Ch] [bp-24h]@35
  int v87; // [sp+930h] [bp-20h]@2
  __int16 v88; // [sp+934h] [bp-1Ch]@46
  __int16 v89; // [sp+936h] [bp-1Ah]@34

  v1 = a1;
  if ( !get_value_post(a1, "service", &v78, 64) )
    return 0;
  v87 = 0;
  if ( !strcmp((const char *)&v78, "hostname") )
  {
    if ( !get_value_post(v1, "hostnameh", v56, 255) || check_unpermitted_chars(v56) )
      v2 = 0;
    else
      v2 = v56;
    v3 = set_hostname(v2);
    goto LABEL_135;
  }
  if ( !strcmp((const char *)&v78, "autosaving") )
  {
    if ( get_value_post(v1, "autosavingh", &v78, 64) )
    {
      v4 = atoi((const char *)&v78);
      v3 = set_autosaving();
      if ( !v4 )
        v3 = saveconf(v3);
      goto LABEL_135;
    }
    return 0;
  }
  if ( !strcmp((const char *)&v78, "fakedns") )
  {
    if ( get_value_post(v1, "fakednsh", &v78, 64) )
    {
      v5 = atoi((const char *)&v78);
      if ( v5 )
        v6 = "@{62}";
      else
        v6 = "@{63}";
      syslog_msg(1, v6);
      v7 = set_fakedns(v5);
LABEL_88:
      v3 = signal_update(v7);
      goto LABEL_135;
    }
    return 0;
  }
  if ( !strcmp((const char *)&v78, "dhcp_restart") )
  {
    v7 = get_value_post(v1, "dhcp_auto_restart_1", &v78, 64);
    if ( v7 )
    {
      get_wan_hw_ifname("wan1", &v85);
      if ( !strcmp((const char *)&v78, "on") )
      {
        v8 = &v85;
        v9 = 1;
      }
      else
      {
        v8 = &v85;
        v9 = 0;
      }
      v7 = set_dhcp_auto_restart(v8, v9);
    }
    goto LABEL_88;
  }
  if ( !strcmp((const char *)&v78, "nologin") )
  {
    if ( !get_value_post(v1, "nologinh", &v78, 64) )
      return 0;
    v10 = atoi((const char *)&v78);
    v3 = set_nologin(v10);
LABEL_135:
    signal_save(v3);
    return 1;
  }
  if ( !strcmp((const char *)&v78, "wbmpopup") )
  {
    if ( !get_value_post(v1, "wbmpopuph", &v78, 64) )
      return 0;
    v11 = atoi((const char *)&v78);
    v3 = set_wbm_popup_flag(v11);
    goto LABEL_135;
  }
  if ( !strcmp((const char *)&v78, "apcplan") )
  {
    if ( !get_value_post(v1, "apcplanh", &v78, 64) )
      return 0;
    v12 = atoi((const char *)&v78);
    v3 = set_apcplan_flag(v12);
    goto LABEL_135;
  }
  if ( !strcmp((const char *)&v78, (const char *)&unk_61A66) )
  {
    v89 = 0;
    if ( get_value_post(v1, "autorebooth", &v78, 64) )
      v86 = atoi((const char *)&v78);
    else
      v86 = 0;
    set_autoreboot_config(&v86);
    memset(&v63, 0, 0x44u);
    v13 = get_value_post(v1, "everyday", &v89, 2);
    v14 = atoi((const char *)&v89);
    v15 = v14 == 0;
    if ( v14 )
      v15 = v13 == 0;
    v16 = !v15;
    if ( v15 )
      v17 = v16;
    else
      v17 = v14;
    v65 = v17;
    if ( !v17 )
    {
      v88 = 0;
      v64 = 1;
      v18 = get_value_post(v1, "sun", &v88, 2);
      v19 = strcmp((const char *)&v88, "1") == 0;
      if ( !v18 )
        v19 = 0;
      if ( v19 )
        v66 = atoi((const char *)&v88);
      else
        v66 = 0;
      v20 = get_value_post(v1, "mon", &v88, 2);
      v21 = strcmp((const char *)&v88, "1") == 0;
      if ( !v20 )
        v21 = 0;
      if ( v21 )
        v67 = atoi((const char *)&v88);
      else
        v67 = 0;
      v22 = get_value_post(v1, "tue", &v88, 2);
      v23 = strcmp((const char *)&v88, "1") == 0;
      if ( !v22 )
        v23 = 0;
      if ( v23 )
        v68 = atoi((const char *)&v88);
      else
        v68 = 0;
      v24 = get_value_post(v1, "wed", &v88, 2);
      v25 = strcmp((const char *)&v88, "1") == 0;
      if ( !v24 )
        v25 = 0;
      if ( v25 )
        v69 = atoi((const char *)&v88);
      else
        v69 = 0;
      v26 = get_value_post(v1, "thu", &v88, 2);
      v27 = strcmp((const char *)&v88, "1") == 0;
      if ( !v26 )
        v27 = 0;
      if ( v27 )
        v70 = atoi((const char *)&v88);
      else
        v70 = 0;
      v28 = get_value_post(v1, "fri", &v88, 2);
      v29 = strcmp((const char *)&v88, "1") == 0;
      if ( !v28 )
        v29 = 0;
      if ( v29 )
        v71 = atoi((const char *)&v88);
      else
        v71 = 0;
      v30 = get_value_post(v1, "sat", &v88, 2);
      v31 = strcmp((const char *)&v88, "1") == 0;
      if ( !v30 )
        v31 = 0;
      if ( v31 )
        v72 = atoi((const char *)&v88);
      else
        v72 = 0;
    }
    v73 = 0;
    if ( get_value_post(v1, "autorebootHour", &v78, 64) )
    {
      v76 = atoi((const char *)&v78);
      v74 = v76;
    }
    if ( get_value_post(v1, "autorebootMin", &v78, 64) )
    {
      v77 = atoi((const char *)&v78);
      v75 = v77;
    }
    remove_all_gen_schedule(&unk_61A66);
    if ( v86 )
      add_gen_schedule(&unk_61A66, &v63);
    v7 = iconfig_remove_config_tag("last_autoboot_stamp");
    goto LABEL_88;
  }
  if ( !strcmp((const char *)&v78, "restart") )
  {
    v32 = "@{42}";
    v33 = 1;
LABEL_94:
    v35 = syslog_msg(v33, v32);
LABEL_103:
    saveconf(v35);
    signal_reboot(3);
    return 2;
  }
  if ( !strcmp((const char *)&v78, "upnp") )
  {
    if ( !get_value_post(v1, "upnph", &v88, 2) )
      return 0;
    v34 = atoi((const char *)&v88);
    set_upnp(v34);
    v32 = "@{42}";
    v33 = 1;
    goto LABEL_94;
  }
  if ( !strcmp((const char *)&v78, "hubapmode") )
  {
    get_ifconfig((int)"br0", (int)&v81, (int)&v80);
    get_value_post(v1, "use_local_gateway", &v79, 32);
    if ( !strcmp((const char *)&v79, "1") && get_ip_value_post(v1, "gw", &v84) )
    {
      set_use_local_gateway(1);
      set_lan_ipconfig(&v81, &v80, &v84);
      get_ip_value_post(v1, "fdns", &v83);
      get_ip_value_post(v1, "sdns", &v82);
      set_dns_shadow("br0", "local", &v83, &v82);
    }
    else
    {
      set_use_local_gateway(0);
      set_lan_ipconfig(&v81, &v80, 0);
    }
    dhcpd_read_config(&v43);
    sf_strncpy(&v46, &v81, 20);
    sf_strncpy(&v47, &v80, 20);
    get_subnet_range(&v81, &v80, &v44, &v45);
    if ( !strcmp((const char *)&v48, (const char *)&v81) )
      sf_strncpy(&v48, &v81, 20);
    v36 = dhcpd_commit_config(&v43);
    v35 = dhcpd_flush_dynamic_lease(v36);
    goto LABEL_103;
  }
  if ( !strcmp((const char *)&v78, "snmp") )
  {
    if ( get_value_post(v1, "snmp_run", &v57, 64) )
    {
      read_snmp_conf(&v49);
      system2("/sbin/iptables -D INPUT -p udp --dport %d -j ACCEPT", v50);
      v49 = strcmp(&v57, "on") == 0;
      if ( v49 )
      {
        get_intvalue_post(v1, "snmp_service_port", &v50);
        if ( get_value_post(v1, "snmp_community", &v57, 128) )
          sf_strncpy(&v51, &v57, 128);
        else
          strcpy((char *)&v51, "");
        if ( get_value_post(v1, "snmp_sysname", &v57, 128) )
          sf_strncpy(&v52, &v57, 128);
        else
          strcpy((char *)&v52, "");
        if ( get_value_post(v1, "snmp_location", &v57, 128) )
          sf_strncpy(&v53, &v57, 128);
        else
          strcpy((char *)&v53, "");
        if ( get_value_post(v1, "snmp_contact", &v57, 128) )
          sf_strncpy(&dest, &v57, 128);
        else
          strcpy(&dest, "");
        if ( get_value_post(v1, "snmp_descr", &v57, 128) )
          sf_strncpy(&v55, &v57, 128);
        else
          strcpy(&v55, "");
      }
      v7 = write_snmp_conf(&v49);
      goto LABEL_88;
    }
    return 0;
  }
  if ( !strcmp((const char *)&v78, "realtime") )
  {
    memset(&s, 0, 0x54u);
    get_value_post(v1, "server_list", &s, 64);
    if ( strcmp(&s, "null") || (get_value_post(v1, "server_edit", &s, 64), !check_unpermitted_chars(&s)) )
    {
      if ( !s )
        strcpy(&s, "null");
      if ( !get_intvalue_post(v1, "summer_flag", &v62) )
        v62 = 0;
      get_intvalue_post(v1, "gmtidx", &v87);
      sf_strncpy(&v59, &byte_987C0[144 * v87], 8);
      v60 = byte_987C0[144 * v87 + 136] == 43;
      v61 = *(_DWORD *)&byte_987C0[144 * v87 + 140];
      v38 = set_timeserver_conf(&s);
      v7 = clear_timed_status(v38);
      goto LABEL_88;
    }
    return 0;
  }
  if ( strcmp((const char *)&v78, "multilang") )
    return 0;
  v39 = get_value_post(v1, "multilang_lang", &v85, 16);
  if ( v39 )
  {
    v40 = set_system_lang(&v85);
    v39 = sub_13494(v40, v41);
  }
  v42 = signal_update(v39);
  signal_save(v42);
  return 3;
}



int __fastcall sub_1BA54(int a1, int a2)
{
  int v2; // r5@1
  int v3; // r4@1
  signed int v4; // r10@1
  const char *v5; // r0@2
  char *v6; // r1@4
  char *v7; // r0@5
  int result; // r0@7
  const char *v9; // r0@10
  int v10; // r1@10
  int v11; // r0@10
  int v12; // r1@10
  int v13; // r1@11
  int v14; // r0@12
  int v15; // r0@13
  int v16; // r1@13
  int v17; // r0@13
  char *v18; // r0@14
  int v19; // r1@15
  int v20; // r0@15
  int v21; // r0@15
  int v22; // r1@15
  int v23; // r0@16
  int v24; // r1@16
  int v25; // r0@17
  int v26; // r0@18
  int v27; // r0@18
  int v28; // r1@18
  int v29; // r0@19
  int v30; // r1@19
  int v31; // r0@20
  int v32; // r0@21
  int v33; // r0@21
  int v34; // r1@21
  int v35; // r0@22
  int v36; // r1@22
  int v37; // r0@23
  int v38; // r0@24
  int v39; // r0@24
  int v40; // r1@24
  int v41; // r0@25
  int v42; // r1@25
  int v43; // r0@26
  int v44; // r0@27
  int v45; // r0@27
  int v46; // r1@27
  int v47; // r0@28
  int v48; // r1@28
  int v49; // r0@29
  int v50; // r0@30
  int v51; // r0@30
  int v52; // r1@30
  int v53; // r0@31
  int v54; // r1@31
  int v55; // r0@32
  int v56; // r0@33
  int v57; // r1@33
  int v58; // r0@34
  int v59; // r1@34
  int v60; // r0@35
  int v61; // r0@36
  int v62; // r1@36
  int v63; // r0@36
  int v64; // r0@36
  int v65; // r1@36
  int v66; // r0@37
  int v67; // r0@39
  int v68; // r1@39
  int v69; // r0@39
  int v70; // r1@39
  int v71; // r0@40
  const char *v72; // r0@42
  int v73; // r1@42
  int v74; // r0@42
  int v75; // r1@42
  int v76; // r0@43
  int v77; // r0@45
  int v78; // r1@45
  int v79; // r0@45
  int v80; // r0@46
  int v81; // r0@46
  int v82; // [sp+8h] [bp-788h]@39
  _BYTE v83[3]; // [sp+291h] [bp-4FFh]@10
  _BYTE v84[3]; // [sp+491h] [bp-2FFh]@10
  char v85; // [sp+591h] [bp-1FFh]@10
  char v86; // [sp+690h] [bp-100h]@33
  char v87; // [sp+6D7h] [bp-B9h]@7
  char v88; // [sp+717h] [bp-79h]@5
  char v89; // [sp+757h] [bp-39h]@42
  char v90; // [sp+767h] [bp-29h]@10
  int v91; // [sp+76Ch] [bp-24h]@33

  v2 = a2;
  v3 = a1;
  sub_1A554(a1, a2);
  sub_133E4("sysconf", "misc");
  v4 = sub_1ADC0(v2);
  if ( v4 != 3 )
  {
    if ( v3 )
    {
      v6 = (char *)get_pvalue(v3, "service");
      if ( !v6 )
      {
        strcpy(&v88, "multilang");
LABEL_10:
        printf("<style>");
        printf("form { margin: 0; }");
        printf(".selected { background-color: #C9D5E9 !important; }");
        printf("</style>");
        printf("<BODY style=\"padding:0px 0px; margin:0px 0px;\">");
        printf("<form method=post action=\"timepro.cgi\" name=\"main_form\">");
        puts("<input type=hidden name=tmenu value=iframe>");
        printf("<input type=hidden name=\"smenu\" value=\"sysconf_misc\">");
        puts("<input type=hidden name=service value=>");
        puts("<input type=hidden name=run value=>");
        puts("<input type=hidden name=hostnameh value=>");
        puts("<input type=hidden name=autosavingh value=>");
        puts("<input type=hidden name=fakednsh value=>");
        puts("<input type=hidden name=dhcp_auto_restart_1 value=>");
        puts("<input type=hidden name=nologinh value=>");
        puts("<input type=hidden name=wbmpopuph value=>");
        puts("<input type=hidden name=apcplanh value=>");
        puts("<input type=hidden name=autorebooth value=>");
        puts("<input type=hidden name=everyday value=>");
        puts("<input type=hidden name=autorebootHour value=>");
        puts("<input type=hidden name=autorebootMin value=>");
        puts("<input type=hidden name=sun value=>");
        puts("<input type=hidden name=mon value=>");
        puts("<input type=hidden name=tue value=>");
        puts("<input type=hidden name=wed value=>");
        puts("<input type=hidden name=thu value=>");
        puts("<input type=hidden name=fri value=>");
        puts("<input type=hidden name=sat value=>");
        puts("<input type=hidden name=restarth value=>");
        puts("<input type=hidden name=upnph value=>");
        printf("<table style=\"border-collapse:collapse; border-style:none none none none; width:100%%;\" cellspacing=0px cellpadding=0px>\n");
        printf("<COL WIDTH=9><COL WIDTH=220><COL width=350><COL>");
        get_system_lang(&v90);
        v9 = (const char *)sub_1A440(&v90);
        strcpy(v84, v9);
        strcpy(v83, "");
        v11 = sub_134F4(950, v10);
        sub_1A180((int)"multilang", v11, (int)v84);
        puts("<input type=hidden name=multilang_lang >");
        memset(&v85, 0, 0xFFu);
        get_hostname(&v85);
        if ( v85 )
        {
          snprintf2(
            v84,
            256,
            "<span id=hostname_status title=\"%s\" style=\" display:block; overflow:hidden; white-space:nowrap;  text-ove"
            "rflow:ellipsis; width:350px; \">%s </span>",
            &v85,
            &v85);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap;  text-overflow:ellipsis;\">%s</span>",
            "hostname",
            "");
        }
        else
        {
          v14 = sub_134F4(958, v12);
          snprintf2(v84, 256, "<span id=hostname_status>%s</span>", v14, 0);
          strcpy(v83, "");
        }
        v15 = sub_134F4(927, v13);
        sub_1A180((int)"hostname", v15, (int)v84);
        sub_130BC(v84, 256);
        strcpy(v83, "");
        v17 = sub_134F4(603, v16);
        sub_1A180((int)"realtime", v17, (int)v84);
        puts("<input type=hidden name=server_list>");
        puts("<input type=hidden name=server_edit>");
        puts("<input type=hidden name=gmtidx>");
        puts("<input type=hidden name=summer_flag>");
        if ( v4 == 1 )
        {
          printf("<script>");
          v18 = sub_1AACC();
          printf("parent.document.getElementsByName('server_edit')[0].value = '%s';", v18);
          printf("if((parent.document.getElementsByName('sysconf_misc_realtime_status')[0]) && parent.document.getElementsByName('sysconf_misc_realtime_status')[0].contentWindow)");
          printf("parent.document.getElementsByName('sysconf_misc_realtime_status')[0].contentWindow.location.reload();");
          printf("</script>");
        }
        strcpy(v84, "");
        strcpy(v83, "");
        v20 = sub_134F4(600, v19);
        v21 = sub_1A180((int)"configmgmt", v20, (int)v84);
        if ( get_autosaving(v21) <= 0 )
        {
          v25 = sub_134F4(900, v22);
          snprintf2(v84, 256, "<span id=autosaving_status>%s</span>", v25, 3);
          strcpy(v83, "");
        }
        else
        {
          v23 = sub_134F4(894, v22);
          snprintf2(v84, 256, "<span id=autosaving_status>%s</span>", v23, 3);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap;  text-overflow:ellipsis;\">%s</span>",
            "auto_saving",
            "");
        }
        v26 = sub_134F4(948, v24);
        v27 = sub_1A180((int)"autosaving", v26, (int)v84);
        if ( get_fakedns(v27) <= 0 )
        {
          v31 = sub_134F4(900, v28);
          snprintf2(v84, 256, "<span id=fakedns_status>%s</span>", v31, 4);
          strcpy(v83, "");
        }
        else
        {
          v29 = sub_134F4(894, v28);
          snprintf2(v84, 256, "<span id=fakedns_status>%s</span>", v29, 4);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap;  text-overflow:ellipsis;\">%s</span>",
            "fakedns",
            "");
        }
        v32 = sub_134F4(949, v30);
        v33 = sub_1A180((int)"fakedns", v32, (int)v84);
        if ( get_nologin(v33) )
        {
          v37 = sub_134F4(122, v34);
          snprintf2(v84, 256, "<span id=nologin_status>%s</span>", v37, 5);
          strcpy(v83, "");
        }
        else
        {
          v35 = sub_134F4(885, v34);
          snprintf2(v84, 256, "<span id=nologin_status>%s</span>", v35, 5);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap; text-overflow:ellipsis;\">%s</span>",
            "nologin",
            "");
        }
        v38 = sub_134F4(957, v36);
        v39 = sub_1A180((int)"nologin", v38, (int)v84);
        if ( get_wbm_popup_flag(v39) <= 0 )
        {
          v43 = sub_134F4(951, v40);
          snprintf2(v84, 256, "<span id=wbm_popup_status>%s</span>", v43, 6);
          strcpy(v83, "");
        }
        else
        {
          v41 = sub_134F4(953, v40);
          snprintf2(v84, 256, "<span id=wbm_popup_status>%s</span>", v41, 6);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap;  text-overflow:ellipsis;\">%s</span>",
            "wbmpopup",
            "");
        }
        v44 = sub_134F4(952, v42);
        v45 = sub_1A180((int)"wbmpopup", v44, (int)v84);
        if ( get_upnp(v45) <= 0 )
        {
          v49 = sub_134F4(900, v46);
          snprintf2(v84, 256, "<span id=upnp_status>%s</span>", v49, 7);
          strcpy(v83, "");
        }
        else
        {
          v47 = sub_134F4(894, v46);
          snprintf2(v84, 256, "<span id=upnp_status>%s</span>", v47, 7);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap; text-overflow:ellipsis;\">%s</span>",
            "upnp",
            "");
        }
        v50 = sub_134F4(1012, v48);
        v51 = sub_1A180((int)"upnp", v50, (int)v84);
        if ( get_apcplan_flag(v51) <= 0 )
        {
          v55 = sub_134F4(900, v52);
          snprintf2(v84, 256, "<span id=apcpd_status>%s</span>", v55, 8);
          strcpy(v83, "");
        }
        else
        {
          v53 = sub_134F4(894, v52);
          snprintf2(v84, 256, "<span id=apcpd_status>%s</span>", v53, 8);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap;  text-overflow:ellipsis;\">%s</span>",
            "apcpd",
            "");
        }
        v56 = sub_134F4(917, v54);
        sub_1A180((int)"apcplan", v56, (int)v84);
        get_autoreboot_config(&v91);
        memset(&v86, 0, 0x44u);
        read_sched_array(&unk_61A66, &v86, 1);
        if ( v91 )
        {
          v58 = sub_134F4(894, v57);
          snprintf2(v84, 256, "<span id=autoreboot_status>%s</span>", v58, 9);
          snprintf2(
            v83,
            512,
            "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap; text-overflow:ellipsis;\">%s</span>",
            &unk_61A66,
            "");
        }
        else
        {
          v60 = sub_134F4(900, v57);
          snprintf2(v84, 256, "<span id=autoreboot_status>%s</span>", v60, 9);
          strcpy(v83, "");
        }
        v61 = sub_134F4(45, v59);
        sub_1A180((int)&unk_61A66, v61, (int)v84);
        snprintf2(v84, 256, "<span id=restart_status></span>");
        snprintf2(
          v83,
          512,
          "<span title=\"%s\" style=\"overflow:hidden; white-space:nowrap; text-overflow:ellipsis;\">%s</span>",
          "restart",
          "");
        v63 = sub_134F4(921, v62);
        v64 = sub_1A180((int)"restart", v63, (int)v84);
        if ( get_use_local_gateway(v64) )
          v66 = 1013;
        else
          v66 = 959;
        v67 = sub_134F4(v66, v65);
        snprintf2(v84, 256, "<span id=hubapmode_status>%s</span>", v67, 11);
        strcpy(v83, "");
        v69 = sub_134F4(928, v68);
        sub_1A180((int)"hubapmode", v69, (int)v84);
        puts("<input type=hidden name=gw1 value=>");
        puts("<input type=hidden name=gw2 value=>");
        puts("<input type=hidden name=gw3 value=>");
        puts("<input type=hidden name=gw4 value=>");
        puts("<input type=hidden name=fdns1 value=>");
        puts("<input type=hidden name=fdns2 value=>");
        puts("<input type=hidden name=fdns3 value=>");
        puts("<input type=hidden name=fdns4 value=>");
        puts("<input type=hidden name=sdns1 value=>");
        puts("<input type=hidden name=sdns2 value=>");
        puts("<input type=hidden name=sdns3 value=>");
        puts("<input type=hidden name=sdns4 value=>");
        puts("<input type=hidden name=use_local_gateway value=>");
        read_snmp_conf(&v82);
        if ( v82 )
          v71 = 894;
        else
          v71 = 900;
        v72 = (const char *)sub_134F4(v71, v70);
        strcpy(v84, v72);
        strcpy(v83, "");
        v74 = sub_134F4(604, v73);
        sub_1A180((int)"snmp", v74, (int)v84);
        puts("<input type=hidden name=snmp_run>");
        puts("<input type=hidden name=snmp_service_port>");
        puts("<input type=hidden name=snmp_community>");
        puts("<input type=hidden name=snmp_sysname>");
        puts("<input type=hidden name=snmp_location>");
        puts("<input type=hidden name=snmp_contact>");
        puts("<input type=hidden name=snmp_descr>");
        strcpy(v84, "");
        strcpy(v83, "");
        get_wan_hw_ifname("wan1", &v89);
        if ( get_dhcp_auto_restart(&v89) )
          v76 = 894;
        else
          v76 = 900;
        v77 = sub_134F4(v76, v75);
        snprintf2(v84, 256, "<span id=dhcp_restart_status>%s</span>", v77, 13);
        v79 = sub_134F4(924, v78);
        sub_1A180((int)"dhcp_restart", v79, (int)v84);
        sub_1A1E0();
        sub_1A1E0();
        printf("</table>");
        printf("</form>");
        printf("</BODY>");
        printf("<script>");
        printf("setTimeout(function() { clickSysconf(document.getElementById('%s')); }, 50);", &v88);
        if ( v4 == 2 )
        {
          printf("setTimeout(function() {");
          v80 = printf("UnMaskIt(parent.document, 'apply_mask');");
          v81 = hwinfo_get_reboot_duration(v80);
          printf("maskRebootMsg(%d, null, parent.document);", v81);
          printf("}, 500);");
        }
        else
        {
          puts("setTimeout(function() {UnMaskIt(parent.document,'apply_mask'); }, 500);");
        }
        v5 = "</script>";
        return printf(v5);
      }
      v7 = &v88;
    }
    else
    {
      result = get_value_post(v2, "service", &v87, 64);
      if ( !result )
        return result;
      v6 = &v87;
      v7 = &v88;
    }
    sf_strncpy(v7, v6, 64);
    goto LABEL_10;
  }
  printf("<BODY style=\"padding:0px 0px; margin:0px 0px;\">");
  printf("<script>top.location.reload();</script>");
  v5 = "</body>";
  return printf(v5);
}




int sub_1C7CC()
{
  char *v0; // r4@1
  const char *v1; // r5@1
  void *v2; // r0@3
  char *v3; // r4@5
  void *v4; // r0@7
  char v6; // [sp+2h] [bp-FEh]@1
  __int16 v7; // [sp+22h] [bp-DEh]@1
  char v8; // [sp+40h] [bp-C0h]@8
  char s1; // [sp+E0h] [bp-20h]@1

  get_si("sw", &v6);
  get_system_lang(&s1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td style=\"padding-left:5px;width:\" colspan=4>");
  printf("<select name=multilang_lang style='height: 20px; width: 200px;'>");
  v0 = "selected";
  v1 = (const char *)&v7;
  if ( strcmp(&s1, "auto") )
    v0 = "";
  v2 = sub_1A440("auto");
  printf("<option value='auto' %s>%s</option>", v0, v2);
  do
  {
    if ( *v1 )
    {
      v3 = "selected";
      if ( strcmp(&s1, v1) )
        v3 = "";
      v4 = sub_1A440(v1);
      printf("<option value='%s' %s>%s</option>", v1, v3, v4);
    }
    v1 += 5;
  }
  while ( v1 != &v8 );
  printf("</select>");
  printf("</td></tr>");
  return printf("</TABLE>");
}




int sub_1C8E4()
{
  int v0; // r1@1
  int v1; // r0@1
  char *v2; // r5@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6
  int v8; // r1@6
  const char *v9; // r0@6
  int v10; // r1@6
  const char *v11; // r0@6
  int v12; // r1@6
  const char *v13; // r0@6
  int v14; // r1@6
  const char *v15; // r0@6
  int v16; // r1@6
  const char *v17; // r0@6
  int v19; // [sp+0h] [bp-2A0h]@1
  int v20; // [sp+4h] [bp-29Ch]@6
  char v21; // [sp+8h] [bp-298h]@6
  char v22; // [sp+88h] [bp-218h]@6
  char v23; // [sp+108h] [bp-198h]@6
  char v24; // [sp+188h] [bp-118h]@6
  char v25; // [sp+208h] [bp-98h]@6

  read_snmp_conf(&v19);
  printf("<style>");
  printf("#snmp_table table input[type=text] { padding-left: 5px; width: 150px;}");
  printf("#snmp_table table tr { height: 19px; }");
  printf("</style>");
  printf("<table style=\"border-collapse:collapse;\" width=100%% cellspacing=0px cellpadding=0px>\n");
  printf("<tr><td width=30%%>");
  v1 = sub_134F4(887, v0);
  v2 = "";
  printf("%s", v1);
  printf("</td>");
  printf("<td>");
  if ( v19 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(894, v3);
  printf("<input type=radio name=snmp_run value=on %s onclick=\"ChangeSNMP();\"> %s", v4, v5);
  print_nbsp(5);
  if ( !v19 )
    v2 = "checked";
  v7 = sub_134F4(900, v6);
  printf(
    "<input type=radio name=snmp_run value=off %s style='margin-left: 20px;' onclick=\"ChangeSNMP();\"> %s",
    v2,
    v7);
  printf("</td></tr>");
  printf("<tr><td>");
  v9 = (const char *)sub_134F4(788, v8);
  printf(v9);
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_service_port size=5 maxlength=5 value=\"%d\">", v20);
  printf("</td></tr>");
  printf("<tr><td>");
  printf("SNMP Community");
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_community maxlength=127 value=\"%s\">", &v21);
  printf("</td></tr>");
  printf("<tr><td>");
  v11 = (const char *)sub_134F4(891, v10);
  printf(v11);
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_sysname value=\"%s\">", &v22);
  printf("</td></tr>");
  printf("<tr><td>");
  v13 = (const char *)sub_134F4(890, v12);
  printf(v13);
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_location value=\"%s\">", &v23);
  printf("</td></tr>");
  printf("<tr><td>");
  v15 = (const char *)sub_134F4(888, v14);
  printf(v15);
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_contact value=\"%s\">", &v24);
  printf("</td></tr>");
  printf("<tr><td>");
  v17 = (const char *)sub_134F4(889, v16);
  printf(v17);
  printf("</td>");
  printf("<td>");
  printf("<input type=text name=snmp_descr value=\"%s\">", &v25);
  printf("</td></tr>");
  printf("</table>");
  return printf("<script> ChangeSNMP(); </script>");
}



int __fastcall sub_1CB88(int a1)
{
  char *v1; // r5@1
  int v2; // r7@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6
  int v8; // r1@6
  int v9; // r4@6
  int v10; // r1@6
  int v11; // r0@6

  v1 = "checked";
  v2 = get_upnp(a1);
  printf("<table width=100%% CELLPADDING=0 CELLSPACING=0 border=0>");
  printf("<tr height=23px>");
  printf("<td style=\"padding-left:5px;\" colspan=4>");
  if ( v2 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(894, v3);
  printf("<input type=radio id=upnp_on name=upnp value=1 %s><label for=upnp_on> %s</label>", v4, v5);
  print_nbsp(10);
  if ( v2 )
    v1 = "";
  v7 = sub_134F4(900, v6);
  printf("<input type=radio id=upnp_off name=upnp value=0 %s><label for=upnp_off> %s</label>", v1, v7);
  printf("</td></tr><tr height=10px><td colspan=4></td></tr> ");
  printf("<tr><td colspan=4 style=\"padding-left:5px;\"");
  printf("<div id=\"upnp_div\">");
  printf("<table width=100%% border=0 cellspacing=0 cellpadding=0>\n");
  puts("<tr><td class=\"st_text_td\">");
  v9 = sub_134F4(1131, v8);
  v11 = sub_134F4(1130, v10);
  printf(
    "<SPAN class=\"movetomain\"><a href=\"javascript:MovePagetoMainURL('natrouterconf','portforward','mode=upnp');\"><u>%"
    "s</u></a> %s</SPAN>",
    v9,
    v11);
  printf("</td>");
  printf("</tr>");
  puts("</table>");
  printf("</div>");
  printf("</td>");
  printf("</tr>");
  printf("<tr><td>");
  printf("<div id=\"upnp_desc\" style=\"border:none; width:100%%; height:80px;\">");
  printf("</div>");
  return printf("</td></tr></table>");
}



int __fastcall sub_1CCFC(int a1)
{
  char *v1; // r5@1
  int v2; // r7@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6
  int v8; // r1@6
  const char *v9; // r0@6

  v1 = "checked";
  v2 = get_apcplan_flag(a1);
  printf("<table width=100%% CELLPADDING=0 CELLSPACING=0 border=0>");
  printf("<tr height=23px>");
  printf("<td style=\"padding-left:5px;\" colspan=4>");
  if ( v2 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(894, v3);
  printf("<input type=radio id=apcplan_on name=apcplan value=1 %s><label for=apcplan_on> %s</label>", v4, v5);
  print_nbsp(10);
  if ( v2 )
    v1 = "";
  v7 = sub_134F4(900, v6);
  printf("<input type=radio id=apcplan_off name=apcplan value=0 %s><label for=apcplan_off> %s</label>", v1, v7);
  printf("</td><tr height=15px><td>&nbsp;</td></tr><tr height=23px><td style=\"padding-left:5px;\">");
  printf("<span class=gray_text><li>");
  v9 = (const char *)sub_134F4(915, v8);
  printf(v9);
  puts("</span>");
  printf("</td>");
  return printf("</tr></table>");
}



int __fastcall sub_1CDE4(int a1)
{
  char *v1; // r5@1
  int v2; // r7@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6

  v1 = "checked";
  v2 = get_wbm_popup_flag(a1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td style=\"padding-left:5px;\" colspan=4>");
  if ( v2 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(953, v3);
  printf("<input type=radio id=wbmpopup_on name=wbmpopup value=1 %s ><label for=wbmpopup_on> %s</label>", v4, v5);
  print_nbsp(10);
  if ( v2 )
    v1 = "";
  v7 = sub_134F4(951, v6);
  printf("<input type=radio id=wbmpopup_off name=wbmpopup value=0 %s ><label for=wbmpopup_off> %s</label>", v1, v7);
  printf("</td></tr>");
  return printf("</TABLE>");
}



int __fastcall sub_1CE90(const char *a1)
{
  const char *v1; // r5@1
  int v2; // r4@1
  int v3; // r0@1
  char *v4; // r5@1
  char *v5; // r6@2
  signed int v6; // r4@7
  int v7; // r1@9
  int v8; // r0@9
  int v9; // r1@9
  int v10; // r0@9
  char v12; // [sp+8h] [bp-20h]@1

  v1 = a1;
  get_wan_hw_ifname(a1, &v12);
  v2 = get_dhcp_auto_restart(&v12);
  v3 = strcmp(v1, "wan1");
  v4 = "checked";
  if ( v2 )
    v5 = "checked";
  else
    v5 = "";
  if ( v2 )
    v4 = "";
  if ( v3 )
    v6 = 2;
  else
    v6 = 1;
  printf("<tr height=23px><td style=\"padding-left:5px;\" colspan=4>");
  v8 = sub_134F4(894, v7);
  printf(
    "<input type=radio id=dhcp_auto_restart_on_%d name=dhcp_auto_restart_%d value=on %s ><label for=dhcp_auto_restart_on_%d> %s</label>",
    v6,
    v6,
    v5,
    v6,
    v8);
  print_nbsp(10);
  v10 = sub_134F4(900, v9);
  printf(
    "<input type=radio id=dhcp_auto_restart_off_%d name=dhcp_auto_restart_%d value=off %s ><label for=dhcp_auto_restart_o"
    "ff_%d> %s</label>",
    v6,
    v6,
    v4,
    v6,
    v10);
  printf("</td></tr>");
  return printf("<tr height=5><td colspan=4>&nbsp;</td></tr>");
}


int sub_1CF7C()
{
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  sub_1CE90("wan1");
  return printf("</TABLE>");
}



int __fastcall sub_1CFA8(int a1)
{
  char *v1; // r5@1
  int v2; // r7@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6
  int v8; // r1@6
  int v9; // r0@6

  v1 = "checked";
  v2 = get_fakedns(a1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td style=\"padding-left:5px;\" colspan=4>");
  if ( v2 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(894, v3);
  printf("<input type=radio id=fakedns_on name=fakedns value=1 %s ><label for=fakedns_on> %s</label>", v4, v5);
  print_nbsp(10);
  if ( v2 )
    v1 = "";
  v7 = sub_134F4(900, v6);
  printf("<input type=radio id=fakedns_off name=fakedns value=0 %s ><label for=fakedns_off> %s</label>", v1, v7);
  printf("</td></tr>");
  printf("<tr height=5><td colspan=4>&nbsp;</td></tr>");
  v9 = sub_134F4(925, v8);
  printf(
    "<tr valign=bottom height=10><td colspan=4 style=\"padding-left:5px;\"><span class=gray_text><LI>%s</span></td></tr>",
    v9);
  return printf("</TABLE>");
}



int __fastcall sub_1D078(int a1)
{
  char *v1; // r5@1
  int v2; // r7@1
  int v3; // r1@1
  char *v4; // r4@2
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6

  v1 = "checked";
  v2 = get_autosaving(a1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=23px><td style=\"padding-left:5px;width:\" colspan=4>");
  if ( v2 )
    v4 = "checked";
  else
    v4 = "";
  v5 = sub_134F4(894, v3);
  printf("<input type=radio id=autosaving_on name=autosaving value=1 %s><label for=autosaving_on> %s</label>", v4, v5);
  print_nbsp(10);
  if ( v2 )
    v1 = "";
  v7 = sub_134F4(900, v6);
  printf("<input type=radio id=autosaving_off name=autosaving value=0 %s><label for=autosaving_off> %s</label>", v1, v7);
  printf("</td></tr>");
  return printf("</TABLE>");
}



int sub_1D120()
{
  int v0; // r1@1
  int v1; // r0@1
  int v2; // r4@1
  int v3; // r0@1
  int v4; // r1@1
  int v5; // r0@1
  int v6; // r1@1
  int v7; // r0@1
  int v8; // r0@2
  char *v9; // r1@2
  char *v10; // r0@6
  int v11; // r5@6
  int v12; // r0@6
  int v13; // r1@6
  int v14; // r0@6
  int v15; // r1@7
  int v16; // r0@8
  int v17; // r1@8
  int v18; // r0@8
  int v19; // r0@8
  int v20; // r0@8
  int v21; // r1@11
  const char *v22; // r0@11
  int v23; // r0@11
  int v24; // r1@11
  const char *v25; // r0@11
  int v26; // r0@11
  char v28; // [sp+4h] [bp-104h]@2
  char s2; // [sp+84h] [bp-84h]@1
  char v30; // [sp+C4h] [bp-44h]@7
  char v31; // [sp+D8h] [bp-30h]@9

  puts("<table cellspacing=0px cellpadding=0px>");
  printf("<tr style='height: 24px;'>");
  v1 = sub_134F4(1006, v0);
  v2 = 0;
  printf("<td style='width:150px;'><span style='padding-left: 5px;'>%s</span></td>", v1);
  printf((const char *)&unk_63526);
  v3 = printf("</td>");
  etr(v3);
  printf("<tr style='height: 24px;'>");
  v5 = sub_134F4(1008, v4);
  printf("<td><span style='padding-left: 5px;'>%s</span></td>\n", v5);
  puts("<td>");
  get_timeserver_conf(&s2);
  printf("<select name=server_list onchange=\"SelectTimeServer()\" style='width: 145px; margin-right: 10px; height: 20px; border: 1px solid #CCC;'>");
  v7 = sub_134F4(1007, v6);
  printf("<option value=null> %s </option>", v7);
  do
  {
    v8 = get_timeserver_list(v2++, &v28);
    v9 = &v28;
    if ( !v8 )
      break;
    printf("<option value=%s ", &v28);
    if ( !strcmp(&v28, &s2) )
      printf("selected");
    printf(">%s</option>", &v28);
  }
  while ( v2 != 15 );
  printf("</select>", v9);
  v10 = sub_1AACC();
  v11 = 0;
  printf(
    "<input type=text name=server_edit value=\"%s\" size=24 maxlength=60 style='border: 1px solid #CCC; padding-left: 4px"
    "; width: 215px; height: 20px;'>",
    v10);
  v12 = puts("</td>");
  etr(v12);
  printf("<tr style='height: 24px;'>");
  v14 = sub_134F4(1009, v13);
  printf("<td><span style='padding-left: 5px;'>%s</span></td>\n", v14);
  puts("<td>");
  puts("<select name=gmtidx style='width: 370px; border: 1px solid #CCC; height: 20px;'>");
  do
  {
    strcmp(&byte_987C0[144 * v11], &v30);
    v15 = v11++;
    printf("<option value=%d %s>%s</option>", v15);
  }
  while ( v11 != 28 );
  puts("</select>");
  v16 = printf("</td>");
  etr(v16);
  printf("<tr style='height: 24px;'>");
  puts("<td></td>");
  puts("<td>");
  printf("<input type=checkbox id=summer_flag name=summer_flag value=1 style='vertical-align: middle;' %s>");
  v18 = sub_134F4(1010, v17);
  printf("<label for=summer_flag>%s</label>", v18);
  v19 = puts("</td>");
  v20 = etr(v19);
  if ( !get_timed_status(v20) && (!get_wan_ip("wan1", &v31) || !get_wan_link("wan1")) )
  {
    printf("<tr height=70>");
    printf("<td colspan=2 align=left>");
    printf("<span class=gray_text>");
    v22 = (const char *)sub_134F4(849, v21);
    v23 = printf(v22);
    br(v23);
    v25 = (const char *)sub_134F4(850, v24);
    printf(v25);
    v26 = printf("</span>");
    etr(v26);
  }
  printf("</table>");
  printf("<iframe name=\"sysconf_misc_realtime_status\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_misc_realtime_status\" style='display: none;' frameborder=no></iframe>");
  puts("<script>");
  puts("SelectTimeServer();");
  return puts("</script>");
}


int sub_1D440()
{
  int v0; // r1@1
  char *v1; // r5@1
  char *v2; // r4@2
  int v3; // r0@4
  int v4; // r1@4
  char *v5; // r4@5
  int v6; // r0@7
  int v7; // r0@7
  int v8; // r1@7
  char *v9; // r4@8
  int v10; // r0@10
  int v11; // r1@10
  char *v12; // r4@11
  int v13; // r0@13
  int v14; // r1@13
  char *v15; // r4@14
  int v16; // r0@16
  int v17; // r1@16
  char *v18; // r4@17
  int v19; // r0@19
  int v20; // r1@19
  char *v21; // r4@20
  int v22; // r0@22
  int v23; // r1@22
  char *v24; // r4@23
  int v25; // r0@25
  int v26; // r1@25
  char *v27; // r4@26
  int v28; // r0@28
  int v29; // r1@28
  int v30; // r0@30
  int v31; // r0@30
  int v32; // r1@30
  const char *v33; // r0@30
  int v34; // r1@30
  const char *v35; // r0@30
  int v36; // r1@30
  const char *v37; // r0@30
  int v38; // r0@30
  int v39; // r1@32
  int v40; // r0@32
  int v41; // r0@32
  int v42; // r1@32
  int v43; // r0@32
  int v45; // [sp+0h] [bp-58h]@1
  int v46; // [sp+24h] [bp-34h]@7
  char v47; // [sp+28h] [bp-30h]@10
  char v48; // [sp+29h] [bp-2Fh]@13
  char v49; // [sp+2Ah] [bp-2Eh]@16
  char v50; // [sp+2Bh] [bp-2Dh]@19
  char v51; // [sp+2Ch] [bp-2Ch]@22
  char v52; // [sp+2Dh] [bp-2Bh]@25
  char v53; // [sp+2Eh] [bp-2Ah]@28
  int v54; // [sp+34h] [bp-24h]@30
  int v55; // [sp+38h] [bp-20h]@30
  int v56; // [sp+44h] [bp-14h]@1

  get_autoreboot_config(&v56);
  memset(&v45, 0, 0x44u);
  read_sched_array(&unk_61A66, &v45, 1);
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%%>");
  printf("<tr height=40>");
  printf("<td style=\"padding-left:5px;padding-top:2px;\">");
  v1 = "checked";
  if ( v56 )
    v2 = "checked";
  else
    v2 = "";
  v3 = sub_134F4(894, v0);
  printf(
    "<input type=radio id=autoreboot_on name=autoreboot value=1 onclick=\"ClickAutoReboot_2(document.sysconf_fm);\" %s><l"
    "abel for=autoreboot_on> %s</label>",
    v2,
    v3);
  print_nbsp(10);
  if ( v56 )
    v5 = "";
  else
    v5 = "checked";
  v6 = sub_134F4(900, v4);
  v7 = printf(
         "<input type=radio id=autoreboot_off name=autoreboot value=0 onclick=\"ClickAutoReboot_2(document.sysconf_fm);\""
         " %s><label for=autoreboot_off> %s</label>",
         v5,
         v6);
  br(v7);
  if ( v46 )
    v9 = "checked";
  else
    v9 = "";
  v10 = sub_134F4(240, v8);
  printf(
    "<input type=checkbox id=everyday name=everyday value=1 onclick=\"ClickEveryDay_2(document.sysconf_fm);\" style='marg"
    "in-left: 5px;' %s><label for=everyday> %s</label>",
    v9,
    v10);
  print_nbsp(10);
  if ( v47 )
    v12 = "checked";
  else
    v12 = "";
  v13 = sub_134F4(255, v11);
  printf(
    " <input type=checkbox id=sun name=sun value=1 style='margin-left: 2px; margin-right: 6px;' %s><label for=sun>%s</label>",
    v12,
    v13);
  if ( v48 )
    v15 = "checked";
  else
    v15 = "";
  v16 = sub_134F4(246, v14);
  printf(" <input type=checkbox id=mon name=mon value=1 %s><label for=mon>%s</label>", v15, v16);
  if ( v49 )
    v18 = "checked";
  else
    v18 = "";
  v19 = sub_134F4(257, v17);
  printf(" <input type=checkbox id=tue name=tue value=1 %s><label for=tue>%s</label>", v18, v19);
  if ( v50 )
    v21 = "checked";
  else
    v21 = "";
  v22 = sub_134F4(260, v20);
  printf(" <input type=checkbox id=wed name=wed value=1 %s><label for=wed>%s</label>", v21, v22);
  if ( v51 )
    v24 = "checked";
  else
    v24 = "";
  v25 = sub_134F4(256, v23);
  printf(" <input type=checkbox id=thu name=thu value=1 %s><label for=thu>%s</label>", v24, v25);
  if ( v52 )
    v27 = "checked";
  else
    v27 = "";
  v28 = sub_134F4(243, v26);
  printf(" <input type=checkbox id=fri name=fri value=1 %s><label for=fri>%s</label>", v27, v28);
  if ( !v53 )
    v1 = "";
  v30 = sub_134F4(247, v29);
  v31 = printf(" <input type=checkbox id=sat name=sat value=1 %s><label for=sat>%s</label>", v1, v30);
  br(v31);
  print_nbsp(1);
  sub_1A294((int)"autorebootHour", v54, 0);
  v33 = (const char *)sub_134F4(382, v32);
  printf(v33);
  print_nbsp(3);
  sub_1A218((int)"autorebootMin", v55, 0);
  v35 = (const char *)sub_134F4(531, v34);
  printf(v35);
  v37 = (const char *)sub_134F4(44, v36);
  v38 = printf(v37);
  if ( !get_timed_status(v38) && v56 )
  {
    br(0);
    v40 = sub_134F4(851, v39);
    v41 = printf("<span class=gray_text>%s</span>", v40);
    br(v41);
    print_nbsp(10);
    v43 = sub_134F4(852, v42);
    printf("<span class=gray_text>%s</span>", v43);
  }
  printf("</td>");
  printf("</tr></table>");
  return printf("<script> ClickAutoReboot_2(document.sysconf_fm);</script>");
}


int sub_1D764()
{
  int v0; // r0@1
  int v1; // r1@1
  char *v2; // r4@1
  char *v3; // r5@2
  int v4; // r0@4
  int v5; // r0@4
  int v6; // r1@4
  int v7; // r0@6
  int v8; // r1@6
  int v9; // r0@6
  int v10; // r1@6
  int v11; // r0@6
  char v13; // [sp+4h] [bp-5Ch]@6
  char v14; // [sp+18h] [bp-48h]@6
  char v15; // [sp+2Ch] [bp-34h]@6

  printf("<table width=100%% CELLPADDING=0 CELLSPACING=0 border=0>");
  printf("<tr height=\"24\">");
  v0 = printf("<td style=\"padding-left:5px;\" colspan=\"4\">");
  v2 = "checked";
  if ( get_use_local_gateway(v0) )
    v3 = "checked";
  else
    v3 = "";
  v4 = sub_134F4(1013, v1);
  printf(
    "<input type=\"radio\" id=use_local_gateway_on name=\"use_local_gateway\" value=\"1\" onclick=\"ChangeLanIPSetupForm("
    "document.sysconf_fm);\" %s><label for=use_local_gateway_on> %s</label>",
    v3,
    v4);
  v5 = print_nbsp(10);
  if ( get_use_local_gateway(v5) )
    v2 = "";
  v7 = sub_134F4(959, v6);
  printf(
    "<input type=\"radio\" id=use_local_gateway_off name=\"use_local_gateway\" value=\"0\" onclick=\"ChangeLanIPSetupForm"
    "(document.sysconf_fm);\" %s><label for=use_local_gateway_off> %s</label>",
    v2,
    v7);
  strcpy(&v15, "");
  strcpy(&v14, "");
  strcpy(&v13, "");
  iconfig_get_value_direct("lan_gateway", &v15);
  get_dns_shadow("br0", "local", &v14, &v13);
  v9 = sub_134F4(493, v8);
  printf(
    "</td></tr><tr height=\"24\"><td style=\"padding-left:5px; width: 150px;\">%s</td><td colspan=\"3\" style=\"padding-left:5px;\">",
    v9);
  sub_11D7C("gw", &v15, 0);
  v11 = sub_134F4(492, v10);
  printf(
    "</td></tr><tr height=\"24\"><td style=\"padding-left:5px;\">%s</td><td colspan=\"3\" style=\"padding-left:5px;\">",
    v11);
  sub_11D7C("fdns", &v14, 0);
  printf("</td></tr><tr height=\"24\"><td style=\"padding-left:5px;\"></td><td colspan=\"3\" style=\"padding-left:5px;\">");
  sub_11D7C("sdns", &v13, 0);
  printf("</td>");
  printf("</tr>");
  printf("</table>");
  return printf("<script>ChangeLanIPSetupForm(document.sysconf_fm);</script>");
}



int sub_1D914()
{
  int v0; // r1@1
  int v1; // r0@1
  int v2; // r4@1
  int v3; // r0@1
  int v4; // r1@1
  int v5; // r0@1
  int v6; // r0@1
  int v7; // r1@1
  int v8; // r4@1
  int v9; // r1@1
  char *v10; // r0@2
  int v11; // r1@4
  int v12; // r0@4
  int v13; // r0@4
  int v14; // r1@4
  int v15; // r0@4
  int v16; // r4@4
  int v17; // r0@4
  int v18; // r0@4

  puts("<table cellspacing=0px cellpadding=0px>");
  printf("<colgroup><col width=150px></colgroup>");
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v1 = sub_134F4(918, v0);
  v2 = v1;
  v3 = hwinfo_get_reboot_duration(v1);
  printf(
    "<input type=button name=save VALUE=\"%s\"  onclick=\"RestoreDefaultConfig(%d);\" style=\"width:120px;\">",
    v2,
    v3);
  puts("</td>");
  v5 = sub_134F4(919, v4);
  v6 = printf("<td><span class=gray_text>%s</span></td>\n", v5);
  etr(v6);
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v8 = sub_134F4(965, v7);
  if ( file_exists("/var/run/savefs.gz") )
    v10 = "";
  else
    v10 = (char *)sub_134F4(960, v9);
  printf("<input type=button name=save VALUE=\"%s\" onclick=\"ApplyBackup('%s')\" style=\"width:120px;\">", v8, v10);
  puts("</td>");
  v12 = sub_134F4(966, v11);
  printf("<td><span class=gray_text>%s</span></td>\n", v12);
  v13 = puts("</td>");
  etr(v13);
  puts("<tr style='height: 26px;'>");
  puts("<td>");
  v15 = sub_134F4(963, v14);
  v16 = v15;
  v17 = hwinfo_get_reboot_duration(v15);
  printf("<input type=button name=save VALUE=\"%s\"  onclick=\"RestoreConfig(%d)\" style=\"width:120px;\">", v16, v17);
  puts("</td>");
  printf("<td>");
  printf("<iframe name=\"sysconf_misc_configmgmt_submit\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_misc_configmgmt_submit\" frameborder=no width=400px height=26px scrolling=no></iframe>");
  printf("<input type=file name=\"restore_config_file\" size=10 maxlength=120 style='width:300px; display: none; color: #888;' disabled>");
  v18 = printf("</td>");
  etr(v18);
  return puts("</table>");
}



int __fastcall sub_1DA9C(const char *a1)
{
  const char *v1; // r4@1
  int result; // r0@2

  v1 = a1;
  if ( !strcmp(a1, "hostname") )
  {
    result = sub_1A9F4();
  }
  else if ( !strcmp(v1, "configmgmt") )
  {
    result = sub_1D914();
  }
  else if ( !strcmp(v1, "autosaving") )
  {
    result = sub_1D078((int)v1);
  }
  else if ( !strcmp(v1, "fakedns") )
  {
    result = sub_1CFA8((int)v1);
  }
  else if ( !strcmp(v1, "dhcp_restart") )
  {
    result = sub_1CF7C();
  }
  else if ( !strcmp(v1, "nologin") )
  {
    result = sub_1AB1C();
  }
  else if ( !strcmp(v1, "wbmpopup") )
  {
    result = sub_1CDE4((int)v1);
  }
  else if ( !strcmp(v1, "upnp") )
  {
    result = sub_1CB88((int)v1);
  }
  else if ( !strcmp(v1, (const char *)&unk_61A66) )
  {
    result = sub_1D440();
  }
  else if ( !strcmp(v1, "restart") )
  {
    result = sub_1A310();
  }
  else if ( !strcmp(v1, "apcplan") )
  {
    result = sub_1CCFC((int)v1);
  }
  else if ( !strcmp(v1, "hubapmode") )
  {
    result = sub_1D764();
  }
  else if ( !strcmp(v1, "realtime") )
  {
    result = sub_1D120();
  }
  else if ( !strcmp(v1, "snmp") )
  {
    result = sub_1C8E4();
  }
  else
  {
    result = strcmp(v1, "multilang");
    if ( !result )
      result = sub_1C7CC();
  }
  return result;
}



int __fastcall sub_1DCFC(int a1, int a2, int a3)
{
  const char *v3; // r6@1
  int v4; // r5@1
  int v5; // r4@1

  v3 = (const char *)a1;
  v4 = a3;
  v5 = a2;
  printf("<TABLE border=0 valign=top CELLSPACING=0 CELLPADDING=0 WIDTH=100%% ID=%s_table STYLE=\"display:none;\">", a1);
  if ( v4 )
    printf(
      "<tr><td height=20 valign=center style=\"padding:3px;width:180px;\">&nbsp; <b>%s</b></td><td align=right>%s</td></tr>",
      v5,
      v4);
  else
    printf("<tr><td colspan=2 height=20 valign=center style=\"padding:3px;\">&nbsp; <b>%s</b></td></tr>", v5);
  printf("<tr height=1px style=\"background-Color:#dddddd\"><td colspan=2 style='width:640px;'></td></tr>");
  printf("<tr><td  colspan=2 valign=top style=\"padding:5px\" >");
  sub_1DA9C(v3);
  return puts((const char *)&unk_6450B);
}



int __fastcall sub_1DD80(int a1)
{
  int v1; // r5@1
  int v2; // r0@1
  char *v3; // r4@1
  int v4; // r3@1
  int v5; // r1@4
  int v6; // r0@4
  int v7; // r1@4
  int v8; // r0@4
  int v9; // r1@4
  int v10; // r0@4
  int v11; // r1@4
  int v12; // r0@4
  int v13; // r1@4
  int v14; // r0@4
  int v15; // r1@4
  int v16; // r0@4
  int v17; // r1@4
  int v18; // r0@4
  int v19; // r1@4
  int v20; // r0@4
  int v21; // r1@4
  int v22; // r0@4
  int v23; // r1@4
  int v24; // r0@4
  int v25; // r1@4
  int v26; // r0@4
  int v27; // r1@4
  int v28; // r0@4
  int v29; // r1@4
  int v30; // r0@4
  int v31; // r1@4
  int v32; // r0@4
  int v33; // r1@4
  int v34; // r0@4
  int v35; // r1@4
  int v36; // r0@4
  int v37; // r4@4
  int v38; // r0@4
  int v40; // [sp+0h] [bp-310h]@1
  char dest; // [sp+200h] [bp-110h]@1

  v1 = a1;
  strcpy(&dest, "");
  printf("<form method=\"post\" action=\"timepro.cgi\" name=\"sysconf_fm\"> ");
  puts("<table style=\"border-collapse:collapse; border-style:none solid solid solid; border-width:0px 1px 1px 1px; border-color:#eeeeee;width:642 \" cellspacing=0px cellpadding=0px>");
  printf("<input type=hidden name=tmenu value=sysconf>");
  printf("<input type=hidden name=\"smenu\" value=\"misc\">");
  v2 = printf("<input type=hidden name=\"act\"id=act  value=\"\">");
  str(v2);
  printf("<td width=100%% height=%d colspan=2 style='border-bottom: 1px solid #CCC;'>", 260);
  v3 = (char *)&v40 + snprintf2(&v40, 128, (const char *)&unk_646B1);
  v4 = get_pvalue(v1, "act");
  if ( v4 || (v4 = get_pvalue(v1, "service")) != 0 )
    snprintf2(v3, 128, "&service=%s", v4);
  printf(
    "<iframe name=\"sysconf_misc_iframe\" src=\"%s\" frameborder=no width=100%% height=340 align=left scrolling=yes></iframe>",
    &v40);
  printf("</td></tr>");
  puts("<tr height=165 style=\"background-Color:#eeeeee\"><td valign=top colspan=2>");
  v6 = sub_134F4(950, v5);
  sub_1DCFC((int)"multilang", v6, 0);
  v8 = sub_134F4(927, v7);
  sub_1DCFC((int)"hostname", v8, 0);
  v10 = sub_134F4(600, v9);
  sub_1DCFC((int)"configmgmt", v10, 0);
  v12 = sub_134F4(948, v11);
  sub_1DCFC((int)"autosaving", v12, 0);
  v14 = sub_134F4(949, v13);
  sub_1DCFC((int)"fakedns", v14, 0);
  v16 = sub_134F4(957, v15);
  sub_1DCFC((int)"nologin", v16, 0);
  v18 = sub_134F4(952, v17);
  sub_1DCFC((int)"wbmpopup", v18, 0);
  v20 = sub_134F4(45, v19);
  sub_1DCFC((int)&unk_61A66, v20, 0);
  v22 = sub_134F4(921, v21);
  sub_1DCFC((int)"restart", v22, 0);
  v24 = sub_134F4(917, v23);
  sub_1DCFC((int)"apcplan", v24, 0);
  v26 = sub_134F4(1012, v25);
  sub_1DCFC((int)"upnp", v26, 0);
  v28 = sub_134F4(928, v27);
  sub_1DCFC((int)"hubapmode", v28, 0);
  v30 = sub_134F4(604, v29);
  sub_1DCFC((int)"snmp", v30, 0);
  v32 = sub_134F4(603, v31);
  sub_1DCFC((int)"realtime", v32, 0);
  v34 = sub_134F4(924, v33);
  sub_1DCFC((int)"dhcp_restart", v34, 0);
  printf("</td></tr>");
  printf("<tr height=1px style=\"background-Color:#dddddd\"><td colspan=2></td></tr>");
  printf("<tr align=right valign=middle height=28 style=\"background-Color:#eeeeee\"><td align=right width=595>");
  printf("</td><td align=right>");
  v36 = sub_134F4(28, v35);
  v37 = v36;
  v38 = hwinfo_get_reboot_duration(v36);
  printf("<input type=button id=apply_bt name=params_bt value=\"%s\" onclick=\"ApplySysconfig(%d);\">", v37, v38);
  printf("</td></tr>");
  printf("</table>");
  return printf("</form>");
}



int __fastcall sub_1E0A8(int a1, int a2)
{
  int v2; // r4@1
  int v3; // r1@1
  int v4; // r0@1
  int v5; // r1@1
  int v6; // r0@1
  int v7; // r0@1
  int v8; // r0@1
  int v9; // r1@1
  int v10; // r4@1
  int v11; // r1@1
  int v12; // r0@1
  int v13; // r1@1
  int v14; // r0@1

  v2 = a1;
  sub_1A554(a1, a2);
  sub_133E4("sysconf", "misc");
  printf("<style>");
  printf("form { margin: 0; }");
  printf("input[type='text'] { border: 1px solid #CCC; }");
  printf("input[type='radio'], input[type='checkbox'] { vertical-align: sub; }");
  printf("</style>");
  sub_1DD80(v2);
  v4 = sub_134F4(27, v3);
  sub_1A358("apply_mask", v4);
  v6 = sub_134F4(954, v5);
  sub_1A358("reboot_mask", v6);
  printf("<style>");
  printf("#%s p { margin: 5px 0 5px 10px; text-align: left; }", &unk_6496B);
  printf("</style>");
  printf("<DIV id=\"%s\" style=\"display:none;\">", &unk_6496B);
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:535px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:200px; top:198px; width:240px; height:75px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"240\" height=\"70\">");
  printf("<tr><td width=\"35px\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v7 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v8 = sub_126C4(v7);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v8);
  printf("</SPAN></td>");
  printf("<td height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\">\n");
  printf("<p id=configmgmt_success style='line-height: 21px; height: 40px;'>");
  v10 = sub_134F4(862, v9);
  v12 = sub_134F4(853, v11);
  printf("%s<br>%s</p>", v10, v12);
  v14 = sub_134F4(861, v13);
  printf("<p id=configmgmt_fail>%s</p>", v14);
  printf("<p id='configmgmt_reboot_seconds'></p>");
  printf("</SPAN></td>");
  return printf((const char *)&unk_60F0E);
}



FILE *__fastcall sub_1E274(int a1, int a2)
{
  FILE *result; // r0@1
  FILE *v3; // r4@1
  signed int v4; // r4@3
  const char *v5; // r0@8
  char v6; // [sp+8h] [bp-98h]@1
  void *ptr; // [sp+88h] [bp-18h]@1
  size_t n; // [sp+8Ch] [bp-14h]@1

  n = 0;
  get_value_post_multipart_file(a2, "restore_config_file", &ptr, &v6);
  result = fopen("/var/run/rsavefs.gz", "w+");
  v3 = result;
  if ( result )
  {
    fwrite(ptr, 1u, n, result);
    fclose(v3);
    system((const char *)&unk_64C49);
    if ( restore_backup_config("/var/run/rsavefs") == -1 )
    {
      if ( v6 )
      {
        syslog_msg(3, "%s%s", "@{22}", &v6, 128, &n);
        v4 = 0;
      }
      else
      {
        v4 = 0;
      }
    }
    else
    {
      syslog_msg(1, "%s%s");
      signal_reboot(3);
      v4 = 1;
    }
    unlink("/var/run/rsavefs.gz");
    unlink("/var/run/rsavefs");
    printf("<script>");
    if ( v4 )
      v5 = "location.href = 'timepro.cgi?tmenu=iframe&smenu=sysconf_misc_configmgmt_submit&act=restore&result=success';";
    else
      v5 = "location.href = 'timepro.cgi?tmenu=iframe&smenu=sysconf_misc_configmgmt_submit&act=restore&result=fail';";
    printf(v5);
    result = (FILE *)printf("</script>");
  }
  return result;
}



int __fastcall sub_1E3A8(int a1, int a2)
{
  int v2; // r4@1
  int v3; // r6@1
  int v4; // r0@8
  int v5; // r0@8
  int v6; // r0@8
  int v7; // r0@8
  int v9; // [sp+0h] [bp-30h]@1

  v2 = a2;
  v3 = a1;
  sub_133E4("sysconf", "misc");
  if ( get_value_post(v2, "act", &v9, 32) )
  {
    if ( !strcmp((const char *)&v9, "default") )
    {
      defaultconf();
      signal_reboot(3);
    }
  }
  else if ( get_value(v3, "act", &v9, 32) && !strcmp((const char *)&v9, "restore") )
  {
    printf("<script>");
    printf("setTimeout(function() {");
    printf("UnMaskIt(parent.document, 'apply_mask');");
    if ( get_value(v3, "result", &v9, 32) && !strcmp((const char *)&v9, "success") )
    {
      printf("parent.document.getElementById('configmgmt_success').style.display = '';");
      v4 = printf("parent.document.getElementById('configmgmt_fail').style.display = 'none';");
      v5 = hwinfo_get_reboot_duration(v4);
      v6 = printf("maskRebootMsg(%d, 'configmgmt_reboot', parent.document);", v5);
      v7 = hwinfo_get_reboot_duration(v6);
      printf("setTimeout(function() { parent.location.reload(); }, %d000);", v7);
    }
    else
    {
      printf("parent.document.getElementById('configmgmt_success').style.display = 'none';");
      printf("parent.document.getElementById('configmgmt_fail').style.display = '';");
      printf("MaskIt(parent.document, 'configmgmt_reboot_mask');");
      printf("setTimeout(function() { UnMaskIt(parent.document, 'configmgmt_reboot_mask'); }, 5000);");
    }
    printf("}, 500);");
    printf("</script>");
  }
  printf("<style>");
  printf("body { margin: 0; background-color: #EEE; }");
  printf("form { margin: 0; }");
  printf("</style>");
  puts("<form method=post action=timepro.cgi name=default_fm enctype=\"multipart/form-data\">");
  puts("<input type=hidden name=tmenu value=iframe>");
  puts("<input type=hidden name=smenu value=sysconf_misc_configmgmt_submit>");
  puts("<input type=hidden name=act value=default>");
  printf("</form>");
  puts("<form method=post action=timepro.cgi name=restore_fm enctype=\"multipart/form-data\" style='padding-top: 2px;'>");
  puts("<input type=hidden name=tmenu value=iframe>");
  puts("<input type=hidden name=smenu value=sysconf_misc_configmgmt_restore>");
  puts("<input type=hidden name=act value=restore>");
  printf("<td><input type=file name=\"restore_config_file\" size=10 maxlength=120 style='width:300px; color: #888;' onchange='validateCFGFile(this);'></td>");
  return printf("</form>");
}



int __fastcall sub_1E5E8(int a1)
{
  int v1; // r5@1
  int v2; // r6@3
  int v3; // r0@5
  int v4; // r1@7
  const char *v5; // r0@7
  int v6; // r0@7
  int v7; // r1@8
  int v8; // r0@8
  int v9; // r0@8
  const char *v10; // r4@8
  int v11; // r1@8
  int v12; // r0@8
  int v13; // r0@8
  char *v14; // r4@8
  char *v15; // r1@9
  int v16; // r1@11
  int v17; // r0@11
  int v18; // r1@11
  int v19; // r0@13
  int v20; // r0@13
  int v21; // r1@13
  int v22; // r0@13
  int v23; // r1@13
  int v24; // r0@13
  int v25; // r0@13
  int v26; // r4@13
  int v27; // r1@13
  int v28; // r0@13
  int v29; // r1@13
  int v30; // r0@13
  int v31; // r1@13
  const char *v32; // r0@13
  int v33; // r0@13
  int v34; // r1@13
  int v35; // r0@13
  int v36; // r1@13
  int v37; // r1@14
  const char *v38; // r0@14
  int v39; // r1@14
  int v40; // r0@16
  int v41; // r0@17
  int v42; // r1@17
  int v43; // r0@17
  int v44; // r1@17
  int v45; // r0@17
  int v46; // r1@17
  int v47; // r0@17
  int v48; // r1@17
  int v49; // r0@17
  int v50; // r0@17
  int v51; // r4@17
  int v52; // r1@17
  int v53; // r0@17
  int v54; // r1@17
  int v55; // r0@17
  int v56; // r1@17
  const char *v57; // r0@17
  int v58; // r0@17
  int v60; // [sp+4h] [bp-4B4h]@13
  int v61; // [sp+84h] [bp-434h]@13
  char v62; // [sp+104h] [bp-3B4h]@13
  char v63; // [sp+1C4h] [bp-2F4h]@13
  char dest; // [sp+2C4h] [bp-1F4h]@5
  char v65; // [sp+3C4h] [bp-F4h]@13
  int v66; // [sp+444h] [bp-74h]@8
  int v67; // [sp+484h] [bp-34h]@1
  int v68; // [sp+4A4h] [bp-14h]@1

  v1 = a1;
  v68 = 0;
  v2 = get_wan_ip("wan1", &v67) || get_default_gateway("br0", &v67);
  strcpy(&dest, "http://download.iptime.co.kr/online_upgrade/ipTIME_Firmware_Wizard(wired).exe");
  sub_133E4("sysconf", "swupgrade");
  puts("<table cellpadding=0px cellspacing=0px style='background-Color: #EEE; width: 641px;'>");
  puts("<tr><td>");
  puts("<table cellspacing=0px cellpadding=0px style='width: 640px; border-bottom: 1px solid #DDD;'>");
  v3 = get_intvalue(v1, "upgradedone", &v68);
  if ( v3 && v68 )
  {
    str(v3);
    printf("<td colspan=2>");
    v5 = (const char *)sub_134F4(990, v4);
    printf(v5);
    v6 = puts("</td>");
    etr(v6);
  }
  printf("<tr style='background-color: #FFF; height: 24px;'>");
  v8 = sub_134F4(983, v7);
  v9 = printf("<td style='width:190px; padding-left: 5px;'>%s</td>", v8);
  v10 = (const char *)get_firmware_version2(v9);
  printf("<td>");
  printf(v10);
  printf("</td>");
  printf("</tr>");
  printf("<tr style='background-color: #F7F7F7; height: 24px;'>");
  v12 = sub_134F4(977, v11);
  printf("<td style='padding-left: 5px;'>%s</td>", v12);
  sub_1236C(&v66, 64);
  printf("<td>%s</td>", &v66);
  printf("</tr>");
  printf("<tr style='background-color: #FFF; height: 24px;'>");
  printf("<td colspan=2></td>");
  printf("</tr>");
  puts("</table></td></tr>");
  puts("<tr><td>");
  v13 = puts("<table cellspacing=0px cellpadding=0px>");
  str(v13);
  printf("<td style=\"height:20px; padding-top: 0px; padding-bottom: 2px; padding-left: 5px; padding-right: 10px;\">");
  v14 = "";
  puts("<form method=post action=timepro.cgi name=view_fm style='margin:0; padding: 5px 0;'>");
  if ( v2 )
    v15 = "checked";
  else
    v15 = "";
  printf(
    "<input type=radio id=firmup_online name=firmup value=online style='vertical-align: bottom;' onclick=\"FirmUpView();\" %s>",
    v15);
  v17 = sub_134F4(982, v16);
  printf("<label for=firmup_online style='margin-right: 35px;'> %s</label>", v17);
  if ( !v2 )
    v14 = "checked";
  v19 = sub_134F4(981, v18);
  printf(
    "<input type=radio id=firmup_manual name=firmup value=manual style='vertical-align: bottom;' onclick=\"FirmUpView();\""
    " %s><label for=firmup_manual> %s</label>",
    v14,
    v19);
  printf("</td>");
  printf("<input type=hidden name=status_code>");
  v20 = printf("</form>");
  etr(v20);
  printf("<tr id=online>");
  puts("<td align=left>");
  printf("<table style='width: 640px;'>");
  printf("<tr height=40 valign=top><td>");
  printf("<table cellpadding=0px cellspacing=0px style='background-color: #FFF; width: 620px; margin: 0 5px; min-height:52px;'><tr><td style='padding: 10px; height: 52px;'>");
  printf("<span ID=firmware_status style='color:gray;'></span>");
  printf("</td></tr></table>");
  printf("</td></tr>");
  printf("<tr height=40 valign=top><td align=right>");
  puts("<form method=post action=timepro.cgi name=firmup2_fm style='margin: 5px 0 0 0; border-width: 1px 0; border-color: #DDD; border-style: solid; padding: 5px;'>");
  v22 = sub_134F4(317, v21);
  printf(
    "<input type=button name=autoup id=cancel_bt style=\"display:none;\" value=\"%s\" onclick=\"CancelFirmUp();\">\n",
    v22);
  v24 = sub_134F4(316, v23);
  printf(
    "<input type=button name=autoup id=onlineupdate_bt value=\"%s\" style='color:gray;' onclick=\"StartFirmUp();\" disabled>\n",
    v24);
  puts("</form>");
  printf("</td></tr>");
  printf("<tr><td>");
  v25 = printf("<table cellpadding=0px cellspacing=0px style='margin-left: 5px;'>");
  v26 = sub_126C4(v25);
  v28 = sub_134F4(991, v27);
  printf(
    "<tr style='height: 24px;'><td><img src='/%s/warning.gif' style='margin: 0 3px 1px 3px; vertical-align: middle;'><b s"
    "tyle='color: gray;'>%s</b></td></tr>",
    v26,
    v28);
  v30 = sub_134F4(314, v29);
  printf((const char *)&unk_659D9, v30);
  printf("<tr style='height: 18px;'><td><span style='color: gray;'>");
  v32 = (const char *)sub_134F4(315, v31);
  printf(v32, &dest);
  printf("</span></td></tr>");
  printf("</table>");
  printf("</td></tr>");
  printf("</table>");
  printf("<iframe name=\"sysconf_swupgrade_online_status\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_swupgrade_online_status\" frameborder=no style='display:none;'></iframe>");
  v33 = printf("</td>");
  etr(v33);
  printf("<tr id=manual>");
  puts("<td align=left>");
  printf("<table style='width: 640px;'>");
  printf("<tr height=40 valign=top><td>");
  printf("<table id=manual_status_table cellpadding=0px cellspacing=0px style='margin: 0 5px; background-color: #FFF; width: 620px;'>");
  v35 = sub_134F4(984, v34);
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px; padding-top: 10px;'>%s</td></tr>", v35);
  get_si("pi", &v60);
  snprintf2(&v63, 256, "%s", &v62);
  snprintf2(&v65, 128, "%s", &v61);
  if ( v63 )
  {
    printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px;'>");
    v38 = (const char *)sub_134F4(985, v37);
    printf(v38, &v63, &v65);
    printf("</td></tr>");
  }
  else if ( *(_BYTE *)sub_134F4(985, v36) )
  {
    v40 = sub_134F4(985, v39);
    printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px;'>%s</td></tr>", v40);
  }
  v41 = sub_134F4(986, v39);
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px;'>%s</td></tr>", v41);
  v43 = sub_134F4(987, v42);
  printf(
    "<tr style='height: 18px;'><td style='color:gray; padding-left: 10px; padding-bottom: 10px;'>%s</td></tr>",
    v43);
  printf("</table>");
  printf("<table id=manual_upload_table cellpadding=0px cellspacing=0px style='margin: 0 5px; background-color: #FFF; width: 620px; display: none;'>");
  v45 = sub_134F4(331, v44);
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px; padding-top: 10px;'>%s</td></tr>", v45);
  v47 = sub_134F4(338, v46);
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px;'>%s</td></tr>", v47);
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px;'></td></tr>");
  printf("<tr style='height: 18px;'><td style='color:gray; padding-left: 10px; padding-bottom: 10px; height: 26px;'></td></tr>");
  printf("</table>");
  printf("</td></tr>");
  printf("<tr><td>");
  printf("<iframe name=\"sysconf_swupgrade_manual_file_form\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_swupgrade_manual_status\" frameborder=no scrolling='no' noresize style='width:100%%; height:39px;'></iframe>");
  puts("<form name='sysconf_swupgrade_manual_file_form' style='margin: 5px 0 0 0; padding: 5px; border-width: 1px 0; border-color: #DDD; border-style: solid; display: none;'>");
  printf("<input type=file name=upgrade size=30 maxlength=120 style='width: 430px; font-size: 12px; color:gray;' disabled>");
  v49 = sub_134F4(979, v48);
  printf(
    "<input type=button name=upload_submit value=\"%s\" style='float: right; font-size: 12px; color: gray;' disabled>\n",
    v49);
  puts("</form>");
  printf("</td></tr>");
  printf("<tr><td>");
  v50 = printf("<table cellpadding=0px cellspacing=0px style='margin-left: 5px;'>");
  v51 = sub_126C4(v50);
  v53 = sub_134F4(991, v52);
  printf(
    "<tr style='height: 24px;'><td><img src='/%s/warning.gif' style='margin: 0 3px 1px 3px; vertical-align: middle;'><b s"
    "tyle='color: gray;'>%s</b></td></tr>",
    v51,
    v53);
  v55 = sub_134F4(314, v54);
  printf((const char *)&unk_659D9, v55);
  printf("<tr style='height: 18px;'><td><span style='color: gray;'>");
  v57 = (const char *)sub_134F4(315, v56);
  printf(v57, &dest);
  printf("</span></td></tr>");
  printf("</table>");
  printf("</td></tr>");
  printf("</table>");
  v58 = printf("</td>");
  etr(v58);
  puts("</table></td></tr>");
  printf("</table>");
  puts("<script>");
  puts("FirmUpView();");
  return puts("</script>");
}



int sub_1ECA8()
{
  int v0; // r4@1
  int v1; // r1@1
  int v2; // r0@1

  v0 = hwinfo_get_max_firmware_size();
  puts("<style type=\"text/css\">");
  printf("body { margin: 0; background-color: #EEE; }");
  puts("</style>");
  printf("<body>");
  sub_133E4("sysconf", "swupgrade");
  puts("<form method=post action=upgrade.cgi enctype=\"multipart/form-data\" name=image_upload style='margin: 5px 0 0 0; height: 22px; padding: 5px; border-width: 1px 0; border-color: #DDD; border-style: solid;'>");
  printf(
    "<input type=file name=upgrade size=30 maxlength=120 style='width: 430px; font-size: 12px; height: 22px; float:left;'"
    " onchange='onChangeForm(this, %d);'>",
    v0);
  puts("<input type=hidden name=act>");
  v2 = sub_134F4(979, v1);
  printf(
    "<input type=button name=upload_submit value=\"%s\" style='float: right; font-size: 12px; height: 22px;' onclick='fir"
    "mwareSubmit();'>\n",
    v2);
  puts("</form>");
  printf("<script>");
  printf("onChangeForm(document.getElementsByName('upgrade')[0], %d);", v0);
  return printf("</script>");
}



int __fastcall sub_1ED74(int a1, int a2)
{
  int v2; // r4@1
  int v3; // r0@1
  int v4; // r5@6
  int v5; // r4@7
  int result; // r0@7
  signed int v7; // r0@8
  int v8; // r9@12
  int v9; // r0@12
  int v10; // r0@12
  int v11; // r10@12
  int v12; // r0@13
  char *v13; // r6@13
  int v14; // r8@15
  int v15; // r0@17
  int v16; // r1@17
  int v17; // r0@18
  int v18; // r7@18
  char *v19; // r4@18
  int v20; // r1@18
  int v21; // r0@18
  int i; // r0@18
  bool v23; // nf@20
  unsigned __int8 v24; // vf@20
  int v25; // r0@22
  int v26; // r0@22
  int v27; // r7@22
  char *v28; // r4@22
  int v29; // r1@22
  int v30; // r0@22
  int j; // r0@22
  int v32; // r0@26
  int v33; // r0@26
  int v34; // r7@26
  char *v35; // r6@26
  int v36; // r1@26
  int v37; // r5@26
  int v38; // r4@26
  int v39; // r0@26
  int v40; // r0@26
  int k; // r4@26
  int v42; // r0@30
  int v43; // r0@30
  int v44; // r7@30
  char *v45; // r4@30
  int v46; // r1@30
  int v47; // r0@30
  int l; // r0@30
  int v49; // r0@34
  int v50; // r0@34
  signed int v51; // r7@34
  char *v52; // r4@34
  int v53; // r1@34
  int v54; // r0@34
  int v55; // r4@34
  int v56; // r4@34
  int v57; // r6@34
  int v58; // r1@34
  int v59; // r5@34
  int v60; // r1@34
  int v61; // r0@34
  int v62; // r0@37
  int v63; // r0@40
  int v64; // r1@45
  int v65; // r0@46
  int v66; // r5@46
  int v67; // r1@47
  int v68; // r0@48
  int v69; // r5@49
  int v70; // r0@49
  int v71; // r0@51
  int v72; // r4@51
  int v73; // r1@51
  const char *v74; // r0@51
  int v75; // r1@52
  const char *v76; // r0@53
  char *v77; // r5@53
  int v78; // r4@53
  int v79; // r1@53
  const char *v80; // r0@53
  const char *v81; // r0@54
  int v82; // r4@55
  int v83; // r1@55
  const char *v84; // r0@55
  int v85; // r1@56
  const char *v86; // r0@56
  char v87[512]; // [sp+8h] [bp-500h]@13
  char v88; // [sp+208h] [bp-300h]@49
  char v89; // [sp+3C8h] [bp-140h]@49
  int v90; // [sp+448h] [bp-C0h]@13
  int v91; // [sp+468h] [bp-A0h]@34
  int v92; // [sp+488h] [bp-80h]@34
  int v93; // [sp+4A8h] [bp-60h]@44
  int v94; // [sp+4C8h] [bp-40h]@1

  v2 = a2;
  sub_133E4("sysconf", "swupgrade");
  v3 = get_value_post(v2, "act", &v94, 32);
  if ( !v3 )
    goto LABEL_12;
  if ( !strcmp((const char *)&v94, "update") )
  {
    set_firmup_status(1);
    v3 = signal_start("firmupui");
    goto LABEL_12;
  }
  if ( !strcmp((const char *)&v94, "cancel") )
  {
    v3 = system("/usr/bin/killall wget");
    goto LABEL_12;
  }
  v3 = strcmp((const char *)&v94, "status");
  v4 = v3;
  if ( v3 )
  {
LABEL_12:
    v8 = hwinfo_get_firmup_duration(v3);
    printf("<html>");
    printf("<form method=post name=firmup_fm action=timepro.cgi>");
    printf("<input type=hidden name=tmenu value=iframe>");
    printf("<input type=hidden name=smenu value=sysconf_swupgrade_online_status>");
    printf("<input type=hidden name=act>");
    printf("</form>");
    v9 = puts("<script>");
    v10 = get_firmup_status(v9);
    v11 = v10;
    if ( v10 )
    {
      snprintf2(&v90, 32, "firmup_counter_%d", v10);
      v12 = istatus_get_intvalue_direct(&v90);
      v13 = v87;
      if ( v12 == -1 )
        v12 = 0;
      v14 = v12 + 1;
      if ( v12 + 1 > 64 )
        v14 = 0;
      snprintf2(&v90, 32, "firmup_counter_%d", v11);
      v15 = istatus_set_intvalue_direct(&v90, v14);
      switch ( v11 )
      {
        case 1:
          v17 = sub_126C4(v15);
          v18 = 0;
          v19 = &v87[snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\">", v17)];
          v21 = sub_134F4(328, v20);
          for ( i = snprintf2(v19, 512, " %s", v21); ; i = snprintf2(v19, 512, ".") )
          {
            v19 += i;
            v24 = __OFSUB__(v18, v14);
            v23 = v18++ - v14 < 0;
            if ( !(v23 ^ v24) )
              break;
          }
          puts("DisableRadio( parent.document.view_fm.firmup);");
          puts("DisableObj( parent.document.getElementById('onlineupdate_bt'));");
          puts("parent.document.getElementById('onlineupdate_bt').style.color = 'gray';");
          puts("ShowObj( parent.document.getElementById('cancel_bt'));");
          goto LABEL_58;
        case 2:
          v25 = puts("DisableRadio( parent.document.view_fm.firmup);");
          v26 = sub_126C4(v25);
          v27 = 0;
          v28 = &v87[snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\">", v26)];
          v30 = sub_134F4(324, v29);
          for ( j = snprintf2(v28, 512, " %s", v30); ; j = snprintf2(v28, 512, ".") )
          {
            v28 += j;
            v24 = __OFSUB__(v27, v14);
            v23 = v27++ - v14 < 0;
            if ( !(v23 ^ v24) )
              break;
          }
          goto LABEL_58;
        case 3:
          puts("DisableRadio( parent.document.view_fm.firmup);");
          v32 = puts("ShowObj( parent.document.getElementById('cancel_bt'));");
          v33 = sub_126C4(v32);
          v34 = 0;
          v35 = &v87[snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\">", v33)];
          v37 = sub_134F4(325, v36);
          v38 = hwinfo_get_max_firmware_size();
          v39 = get_filesize("/tmp/firmware");
          v40 = sub_43AF4(100 * v39, v38);
          for ( k = (int)&v35[snprintf2(v35, 512, " %s (%d %%) ", v37, v40)]; ; k += snprintf2(k, 512, ".") )
          {
            v24 = __OFSUB__(v34, v14);
            v23 = v34++ - v14 < 0;
            if ( !(v23 ^ v24) )
              break;
          }
          goto LABEL_58;
        case 4:
          puts("DisableRadio( parent.document.view_fm.firmup);");
          v42 = puts("HideObj( parent.document.getElementById('cancel_bt'));");
          v43 = sub_126C4(v42);
          v44 = 0;
          v45 = &v87[snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\">", v43)];
          v47 = sub_134F4(322, v46);
          for ( l = snprintf2(v45, 512, " %s", v47); ; l = snprintf2(v45, 512, ".") )
          {
            v45 += l;
            v24 = __OFSUB__(v44, v14);
            v23 = v44++ - v14 < 0;
            if ( !(v23 ^ v24) )
              break;
          }
          goto LABEL_58;
        case 5:
          puts("DisableRadio( parent.document.view_fm.firmup);");
          puts("HideObj( parent.document.getElementById('cancel_bt'));");
          v49 = get_ifconfig((int)"br0", (int)&v92, (int)&v91);
          v50 = sub_126C4(v49);
          v51 = 0;
          v52 = &v87[snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\">", v50)];
          v54 = sub_134F4(330, v53);
          v55 = (int)&v52[snprintf2(v52, 512, " %s", v54)];
          v56 = v55 + snprintf2(v55, 512, "<span id=firmup_dot></span><br>");
          v57 = snprintf2(v56, 512, "&nbsp;&nbsp;&nbsp;&nbsp;");
          v59 = sub_134F4(857, v58);
          v61 = sub_134F4(879, v60);
          snprintf2(v56 + v57, 512, "(%s <span id=firmup_duration>%d</span>%s)", v59, v8, v61);
          set_firmup_status(100);
          goto LABEL_59;
        case 6:
          strcpy(v87, "");
          goto LABEL_57;
        default:
          goto LABEL_57;
        case 10:
        case 14:
          puts("EnableRadio( parent.document.view_fm.firmup);");
          puts("EnableObj( parent.document.getElementById('onlineupdate_bt'));");
          puts("parent.document.getElementById('onlineupdate_bt').style.color = '';");
          puts("HideObj( parent.document.getElementById('cancel_bt'));");
          if ( v11 == 14 )
            v62 = 326;
          else
            v62 = 327;
          v13 = v87;
          break;
        case 11:
          v62 = 321;
          break;
        case 12:
          v62 = 323;
          break;
        case 13:
          v62 = 329;
          break;
      }
      v63 = sub_134F4(v62, v16);
      snprintf2(v13, 512, " %s", v63);
      set_firmup_status(0);
    }
    else if ( get_wan_ip("wan1", &v93) || get_default_gateway("br0", &v93) )
    {
      v69 = get_firmupcheck_status();
      get_si("pi", &v88);
      v70 = snprintf2(&v89, 128, &v88);
      switch ( v69 )
      {
        case 0:
          v70 = signal_start("firmupcheck");
          goto LABEL_51;
        case 1:
LABEL_51:
          v71 = sub_126C4(v70);
          v72 = snprintf2(v87, 512, "<img width=10 height=10 src=\"/%s/apply_ani.gif\"> ", v71);
          v74 = (const char *)sub_134F4(320, v73);
          snprintf2(&v87[v72], 512, v74, &v89);
LABEL_58:
          v51 = 1;
          goto LABEL_59;
        default:
          break;
        case 3:
          set_firmupcheck_status(0);
          if ( get_firmupcheck_version(&v90) )
          {
            v76 = (const char *)sub_134F4(339, v75);
            v51 = 0;
            v77 = &v87[snprintf2(v87, 512, v76, &v90)];
            v78 = snprintf2(v77, 512, "<br>");
            v80 = (const char *)sub_134F4(340, v79);
            snprintf2(&v77[v78], 512, v80);
            puts("EnableObj( parent.document.getElementById('onlineupdate_bt'));");
            puts("parent.document.getElementById('onlineupdate_bt').style.color = '';");
            puts("HideObj( parent.document.getElementById('cancel_bt'));");
          }
          else
          {
            v81 = (const char *)sub_134F4(318, v75);
            v51 = 0;
            snprintf2(v87, 512, v81);
          }
          goto LABEL_59;
        case 4:
          v82 = get_firmware_version2(v70);
          set_firmupcheck_status(0);
          v84 = (const char *)sub_134F4(319, v83);
          snprintf2(v87, 512, v84, v82);
          break;
        case 5:
          set_firmupcheck_status(0);
          v86 = (const char *)sub_134F4(318, v85);
          snprintf2(v87, 512, v86);
          break;
      }
    }
    else
    {
      v65 = sub_134F4(48, v64);
      v66 = snprintf2(v87, 512, "%s<br>", v65);
      if ( !get_wan_link("wan1") && !get_default_gateway("br0", &v93) )
      {
        v68 = sub_134F4(49, v67);
        v51 = v11;
        snprintf2(&v87[v66], 512, "<br>%s", v68);
LABEL_59:
        printf("if(parent.document.getElementById('firmware_status'))");
        printf("parent.document.getElementById('firmware_status').innerHTML = '%s';\n", v87);
        if ( v11 == 5 )
        {
          printf("parent.PrintRemainTime('firmup_duration',%d);\n", v8);
          puts("PrintDot('firmup_dot',64,64);");
        }
        if ( v51 == 1 )
          printf("setTimeout(function() { location.href = 'timepro.cgi?tmenu=iframe&smenu=sysconf_swupgrade_online_status'; }, 3000);");
        puts("</script>");
        return printf("</html>");
      }
    }
LABEL_57:
    v51 = 0;
    goto LABEL_59;
  }
  v5 = get_firmup_status(0);
  result = printf("Status:%d", v5);
  if ( v5 == 5 )
  {
    v7 = 100;
  }
  else
  {
    if ( v5 <= 9 )
      return result;
    v7 = v4;
  }
  return set_firmup_status(v7);
}



int __fastcall sub_1F610(int a1)
{
  int v1; // r5@1
  int v3; // [sp+0h] [bp-50h]@1
  char v4; // [sp+20h] [bp-30h]@1

  v1 = a1;
  get_wan_type(a1, &v4);
  get_wan_hw_ifname(v1, &v3);
  sub_133E4("netconf", "wansetup");
  puts("<script language=JavaScript>");
  printf("ShowWansetup('%s','%s');", &v3, &v4);
  puts("check_dns()");
  puts("OnCheckEnableLCP();");
  return puts("</script>");
}



int __fastcall sub_1F698(int a1, _BYTE *a2, int a3, int a4)
{
  int v4; // r6@1
  int v5; // r7@1
  int v6; // r4@1
  int v7; // r1@3
  char *v8; // r1@6
  char *v9; // r0@7
  char *v10; // r1@9
  char *v11; // r0@10
  char *v12; // r1@12
  char *v13; // r0@13
  char *v14; // r1@15
  char *v15; // r0@16
  char *v16; // r5@21
  signed int v17; // r4@21
  char *v18; // r5@22
  signed int v19; // r4@22
  int result; // r0@23
  bool v21; // zf@27
  int v22; // r0@30
  char *v23; // r3@30
  char v24; // [sp+18h] [bp-40h]@7
  char v25; // [sp+1Dh] [bp-3Bh]@10
  char v26; // [sp+22h] [bp-36h]@13
  char v27; // [sp+27h] [bp-31h]@16
  char dest; // [sp+2Ch] [bp-2Ch]@3

  v4 = a1;
  v5 = a3;
  v6 = a4;
  if ( a2 && *a2 )
    sf_strncpy(&dest, a2, 20);
  else
    strcpy(&dest, "");
  if ( dest )
  {
    v8 = strtok(&dest, ".");
    if ( v8 )
    {
      v9 = &v24;
    }
    else
    {
      v9 = &v24;
      v8 = "0";
    }
    strcpy(v9, v8);
    v10 = strtok(0, ".");
    if ( v10 )
    {
      v11 = &v25;
    }
    else
    {
      v11 = &v25;
      v10 = "0";
    }
    strcpy(v11, v10);
    v12 = strtok(0, ".");
    if ( v12 )
    {
      v13 = &v26;
    }
    else
    {
      v13 = &v26;
      v12 = "0";
    }
    strcpy(v13, v12);
    v14 = strtok(0, ".");
    if ( v14 )
    {
      v15 = &v27;
    }
    else
    {
      v15 = &v27;
      v14 = "0";
    }
    strcpy(v15, v14);
  }
  else
  {
    v24 = 0;
    v27 = 0;
    v26 = 0;
    v25 = 0;
  }
  if ( v6 )
  {
    v18 = &v24;
    v19 = 1;
    do
    {
      printf(
        "<input type=text maxlength=3 size=3 id=\"disabled_%s%d\" style=\"width:28pt; ime-mode:disabled; background-color"
        ":#EEEEEE;\" value=\"%s\" disabled>",
        v4,
        v19,
        v18);
      v21 = v19 == 4;
      result = 46;
      ++v19;
      if ( !v21 )
        result = putchar(46);
      v18 += 5;
    }
    while ( v19 != 5 );
  }
  else
  {
    v16 = &v24;
    v17 = 1;
    while ( 1 )
    {
      v21 = v5 == 4;
      if ( v5 == 4 )
        v21 = v17 == 4;
      if ( v21 )
        break;
      v22 = sub_134F4(401, v7);
      v23 = v16;
      v16 += 5;
      printf(
        "<input type=text name=\"%s%d\" maxlength=3 size=3 style=\"width:28pt; ime-mode:disabled;\" value=\"%s\" onfocus="
        "\"this.select();\"\t\t\t    onkeyup=\"IPKeyUp('%s',%d);\" onkeypress=\"return IPKeyDown('%s', %d)\" title=\"%s%d\">",
        v4,
        v17,
        v23,
        v4,
        v17,
        v4,
        v17,
        v22,
        v17,
        *(_DWORD *)&v24);
      v21 = v17 == 4;
      result = 46;
      ++v17;
      if ( !v21 )
        result = putchar(46);
      if ( v17 == 5 )
        return result;
    }
    result = printf(
               "<input type=text name=\"%s%d\" maxlength=3 size=3 style=\"width:28pt; ime-mode:disabled; background-color"
               ":#eeeeee;\" value=\"%s\" readonly>",
               v4,
               4,
               &v27);
  }
  return result;
}



int __fastcall sub_1F87C(int a1, int a2, _BYTE *a3, int a4)
{
  int v4; // r4@1
  _BYTE *v5; // r7@1
  int v6; // r8@1
  int v7; // r10@1
  int v8; // r1@1
  int v9; // r0@1
  char *v10; // r5@1
  _BYTE *v11; // r1@2
  int v12; // r1@4
  int v13; // r0@4
  int v14; // r0@4
  int v15; // r0@6
  char v17; // [sp+18h] [bp-140h]@4
  char v18; // [sp+118h] [bp-40h]@1

  v4 = a1;
  v5 = a3;
  v6 = a4;
  v7 = a2;
  puts("<td class=\"wansetup_main_td\">");
  v9 = sub_134F4(733, v8);
  v10 = "";
  printf("<span class=\"wansetup_main_p\">%s</span></td>\n", v9);
  puts("<td class=\"wansetup_main_td\">");
  snprintf2(&v18, 32, "hw_%s", v4);
  if ( *v5 )
    v11 = v5;
  else
    v11 = 0;
  sub_121A0(&v18, v11, v6);
  printf((const char *)&unk_669D1);
  printf(
    "<input type=checkbox id=\"macchk_%s\" class=navi_chk name=hw_conf_%s %s onclick=\"SetHWOnCheckEnableHWButton(this,'h"
    "w_%s','%s','macbutton_%s'); setdefaultmac(this, 'hw_%s', '%s');\"><label for=\"macchk_%s\">\n",
    v4,
    v4);
  v13 = sub_134F4(694, v12);
  printf("<span class=\"wansetup_main_span\">%s</span></label>", v13);
  snprintf2(&v17, 256, (const char *)&unk_66ABF, v4, v4, v7, v4, v4, v5, v4);
  v14 = snprintf2(&v18, 32, "macbutton_%s", v4);
  if ( !*v5 )
    v10 = "disabled";
  v15 = sub_126C4(v14);
  printf(
    "<button type=\"button\" class=\"wansetup_main_button\" name=\"%s\" style=\"margin-left:5px;\" onclick=\"onclick_macs"
    "earchbtn('hw_%s')\" %s>\t\t<img src=\"/%s/fw_search.gif\" style=\"width:16px; height:16px; padding:0; margin:0;\"></button>",
    &v18,
    v4,
    v10,
    v15);
  return printf("</td>");
}



int __fastcall sub_1F9DC(const char *a1, int a2, int a3)
{
  int v3; // r5@1
  char *v4; // r4@1
  const char *v5; // r7@1
  int v6; // r10@1
  int v7; // r8@4
  int v8; // r0@4
  char *v9; // r4@6
  int v10; // r1@10
  int v11; // r0@12
  char v13; // [sp+10h] [bp-1C0h]@1
  char v14; // [sp+90h] [bp-140h]@4
  char v15; // [sp+110h] [bp-C0h]@4
  char v16; // [sp+190h] [bp-40h]@3

  v3 = a2;
  v4 = &v13;
  v5 = a1;
  v6 = a3;
  get_wan_hw_ifname(a2, &v13);
  if ( !strcmp(v5, "pppoe") || !strcmp(v5, "pptp") )
  {
    v4 = &v16;
    get_pppoe_ifname(v3, &v16);
  }
  v7 = get_mtu_value(v4, 1);
  snprintf2(&v15, 128, "mtu.%s.%s.check", v5, &v13);
  snprintf2(&v14, 128, "mtu.%s.%s", v5, &v13);
  v8 = iconfig_get_intvalue_direct(&v15);
  if ( !v7 )
    v7 = v6;
  v9 = "checked";
  if ( v8 != -1 )
    v5 = (const char *)v8;
  if ( v8 == -1 )
    v5 = 0;
  printf("<td class=\"wansetup_main_td\">");
  puts("<span class=\"wansetup_main_p\">MTU</span>");
  printf("</td>");
  printf(
    "<td class=\"wansetup_main_td\"><input class=\"navi_text\" style=\"width:160px;\" type=text name=%s maxlength=4 value=%d></td>\n",
    &v14,
    v7);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\">");
  if ( !v5 )
    v9 = "";
  v11 = sub_134F4(731, v10);
  printf(
    "<input type=checkbox class=navi_chk id=\"mtuchk_%s\" name='%s' %s onclick=\"OnCheckEnableMTU(this, '%s')\">\t\t<labe"
    "l for=\"mtuchk_%s\"><span class=\"wansetup_main_span\">%s</span></label>\n",
    &v15,
    &v15,
    v9,
    &v14,
    &v15,
    v11);
  return printf("</td>");
}



int __fastcall sub_1FB50(int a1, int a2)
{
  int v2; // r11@1
  int v3; // r1@1
  const char *v4; // r0@1
  char *v5; // r4@1
  int v6; // r0@1
  int v7; // r1@1
  char *v8; // r1@2
  int v9; // r1@4
  int v10; // r0@4
  char *v11; // r1@5
  int v12; // r1@7
  int v13; // r0@7
  char *v14; // r1@8
  int v15; // r1@10
  int v16; // r0@10
  char *v17; // r0@10
  int v18; // r1@10
  int v19; // r0@10
  int v20; // r1@10
  int v21; // r0@12
  int v22; // r1@12
  int v23; // r0@12
  int v24; // r1@12
  int v25; // r0@12
  int v26; // r1@14
  int v27; // r0@14
  int v28; // r1@14
  int v29; // r0@14
  int v30; // r1@14
  int v31; // r0@14
  int v32; // r1@14
  int v33; // r0@14
  int v34; // r1@14
  int v35; // r0@14
  int v36; // r1@14
  int v37; // r0@14
  int v38; // r1@14
  int v39; // r0@14
  int v40; // r1@14
  int v41; // r0@14
  int v42; // r1@14
  int v43; // r0@14
  int v44; // r1@16
  int v45; // r0@16
  int v46; // r1@16
  int v47; // r0@16
  char *v48; // r1@17
  int v49; // r1@19
  int v50; // r0@19
  int v51; // r1@19
  int v52; // r0@19
  int v53; // r1@19
  int v54; // r0@19
  int v55; // r1@19
  int v56; // r0@19
  int v57; // r1@19
  int v58; // r0@19
  char *v59; // r1@20
  int v60; // r1@22
  int v61; // r0@22
  int v62; // r1@22
  int v63; // r0@22
  int v64; // r1@22
  int v65; // r0@22
  int v66; // r1@22
  int v67; // r0@22
  int v68; // r1@24
  int v69; // r0@24
  int v70; // r1@24
  int v71; // r0@24
  int v72; // r1@24
  int v73; // r0@24
  int v74; // r1@24
  int v75; // r0@24
  int v77; // [sp+Ch] [bp-334h]@10
  char v78; // [sp+10h] [bp-330h]@14
  char v79; // [sp+90h] [bp-2B0h]@14
  int v80; // [sp+138h] [bp-208h]@19
  int v81; // [sp+13Ch] [bp-204h]@19
  int v82; // [sp+140h] [bp-200h]@19
  int v83; // [sp+148h] [bp-1F8h]@19
  __int16 v84; // [sp+14Eh] [bp-1F2h]@1
  __int16 v85; // [sp+1CEh] [bp-172h]@1
  __int16 v86; // [sp+20Eh] [bp-132h]@1
  __int16 v87; // [sp+24Eh] [bp-F2h]@1
  char v88; // [sp+26Eh] [bp-D2h]@7
  __int16 v89; // [sp+282h] [bp-BEh]@7
  __int16 v90; // [sp+296h] [bp-AAh]@10
  __int16 v91; // [sp+2AAh] [bp-96h]@14
  __int16 v92; // [sp+2BEh] [bp-82h]@14
  __int16 v93; // [sp+2D2h] [bp-6Eh]@12
  __int16 v94; // [sp+2E6h] [bp-5Ah]@10
  __int16 v95; // [sp+2FAh] [bp-46h]@10
  __int16 v96; // [sp+30Eh] [bp-32h]@1

  v2 = a2;
  strcpy((char *)&v86, "");
  strcpy((char *)&v85, "");
  get_wan_hw_ifname(v2, &v96);
  get_wan_type(v2, &v87);
  v4 = (const char *)sub_134F4(667, v3);
  v5 = "";
  strcpy((char *)&v84, v4);
  printf("<COL width=\"180\"><COL width=\"200\"><COL width=\"%%%%\">");
  puts("<form method=\"post\" action=\"timepro.cgi\" name=\"netconf_wansetup\">");
  puts("<input type=hidden name=\"tmenu\" value=\"netconf\">");
  puts("<input type=hidden name=\"smenu\" value=\"wansetup\">");
  puts("<input type=hidden name=\"act\" value=\"\">");
  puts("<input type=hidden name=\"ocolor\" value=\"\">");
  printf("<input type=hidden name=\"wan\" value=\"%s\">\n", v2);
  v6 = printf("<input type=hidden name=\"ifname\" value=\"%s\">\n", &v96);
  v7 = check_valid_account(v6) == 0;
  printf("<input type=hidden name=\"nopassword\" value=\"%d\">");
  puts("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"border-top:1px #CCC solid;\"><td class=\"wansetup_main_td\" colspan=\"3\"> ");
  if ( !strcmp((const char *)&v87, "dynamic") )
    v8 = "checked";
  else
    v8 = "";
  printf(
    "<input type=radio id=\"wan_type_id1\" name=\"wan_type\" class=\"navi_radio\" value=\"dynamic\" %s onclick=\"ShowWans"
    "etup('%s','dynamic')\"><label for=\"wan_type_id1\" style=\"display:inline-block; vertical-align:middle;\">",
    v8,
    &v96);
  v10 = sub_134F4(656, v9);
  printf("<span class=\"wansetup_main_span\" style=\"font-weight:700;\">%s</span></label></td></tr>\n", v10);
  puts("<tr class=\"wansetup_main_tr\" height=\"24\"><td class=\"wansetup_main_td\" colspan=\"3\"> ");
  if ( !strcmp((const char *)&v87, "pppoe") )
    v11 = "checked";
  else
    v11 = "";
  printf(
    "<input type=radio id=\"wan_type_id2\" name=\"wan_type\" class=\"navi_radio\" value=\"pppoe\" %s onclick=\"ShowWanset"
    "up('%s','pppoe')\"><label for=\"wan_type_id2\" style=\"display:inline-block; vertical-align:middle;\">",
    v11,
    &v96);
  v13 = sub_134F4(664, v12);
  printf("<span class=\"wansetup_main_span\" style=\"font-weight:700;\">%s</span></label></td></tr>", v13);
  strcpy(&v88, "");
  strcpy((char *)&v89, "");
  puts("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"border-bottom:1px #CCC solid;\"><td class=\"wansetup_main_td\" colspan=\"3\"> ");
  if ( !strcmp((const char *)&v87, "static") )
    v14 = "checked";
  else
    v14 = "";
  printf(
    "<input type=radio id=\"wan_type_id3\" name=\"wan_type\" class=\"navi_radio\" value=\"static\" %s onclick=\"ShowWanse"
    "tup('%s','static')\"><label for=\"wan_type_id3\" style=\"display:inline-block; vertical-align:middle;\">",
    v14,
    &v96);
  v16 = sub_134F4(666, v15);
  printf("<span class=\"wansetup_main_span\" style=\"font-weight:700;\">%s</span></label></td></tr>", v16);
  get_hwaddr_kernel(&v96, &v89);
  convert_mac(&v89);
  v17 = getenv("REMOTE_ADDR");
  get_internal_pc_hardware_address(v17, &v90);
  get_hwaddr_cloned(&v96, &v88);
  v77 = v88 == 0;
  strcmp((const char *)&v87, "dynamic");
  printf("<tr id=\"dynamic\" class=\"wansetup_main_tr\" style=\"display:%s;\"><td colspan=\"3\">");
  printf("<table class=\"v3_table wansetup_main_table\" width=\"100%%\">");
  printf("<COL width=\"180\"><COL width=\"200\"><COL width=\"%%%%\">");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v19 = sub_134F4(216, v18);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v19);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_ifconfig((int)&v96, (int)&v95, (int)&v94);
  sub_1F698((int)"dynamicip", &v95, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\">");
  if ( !get_dhclient_block_private_ip(&v96) )
    v5 = "checked";
  v21 = sub_134F4(651, v20);
  printf(
    "<input type=checkbox id=\"aprchkid\" class=\"navi_chk\" name=\"allow_private\" %s>\t\t<label for=\"aprchkid\"><span "
    "class=\"item_text wansetup_main_span\">%s</span></label>",
    v5,
    v21);
  printf("</td></tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v23 = sub_134F4(907, v22);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v23);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"dynamicsm", &v94, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v25 = sub_134F4(345, v24);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v25);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_default_gateway(&v96, &v93);
  if ( !strncmp((const char *)&v93, "ppp", 3u) )
    sf_strncpy(&v93, &v95, 20);
  sub_1F698((int)"dynamicgw", &v93, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  get_dns_shadow(&v96, "dynamic", &v92, &v91);
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v27 = sub_134F4(227, v26);
  printf("<td class=\"wansetup_main_td\"><span class=\"wansetup_main_p\">%s</span>\n", v27);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)&unk_67565, &v92, 1, 0);
  puts((const char *)&unk_67572);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v29 = sub_134F4(874, v28);
  printf("<td class=\"wansetup_main_td\"><span class=\"wansetup_main_p\">%s</span>\n", v29);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"sdns_dynamic", &v91, 1, 0);
  puts("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_manual_dns_flag(&v96, "dynamic");
  printf("<input type=checkbox name=\"dns_dynamic_chk\" class=navi_chk %s onclick=\"check_dns_dynamic();\" id=\"dns_dynamic_chkid\">\n");
  v31 = sub_134F4(637, v30);
  printf("<label for=\"dns_dynamic_chkid\"><span class=\"wansetup_main_span\">%s</span></label>\n", v31);
  puts("</td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  sub_1F87C((int)"dynamic", (int)&v90, &v89, v77);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  sub_1F9DC("dynamic", v2, 1500);
  printf("</tr>");
  printf(
    "<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">\t\t<td class=\"wansetup_main_td\" cols"
    "pan=\"3\"></td></tr>",
    "F7F7F7");
  printf("</table></td></tr>");
  read_pppoe_option(v2, &v78);
  strcmp((const char *)&v87, "pppoe");
  printf("<tr id=\"pppoe\" class=\"wansetup_main_tr\" style=\"display:%s;\"><td colspan=\"3\">");
  printf("<table class=\"v3_table wansetup_main_table\" width=\"100%%\">");
  printf("<COL width=\"180\"><COL width=\"200\"><COL width=\"%%%%\">");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v33 = sub_134F4(660, v32);
  printf("<td class=wansetup_main_td><span class=\"wansetup_main_p\">%s</span></td>", v33);
  printf(
    "<td class=wansetup_main_td><input class=navi_text type=text style=\"width:160px;\" name=\"userid\" maxlength=63 valu"
    "e=\"%s\"></td>\n",
    &v78);
  printf("<td class=wansetup_main_td></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v35 = sub_134F4(663, v34);
  printf((const char *)&unk_67821, v35);
  printf("<td class=wansetup_main_td><input class=\"navi_text\" type=password style=\"width:160px;\" name=\"passwd\" \t\tid=\"passwd_passwd\" maxlength=63 value=\"");
  sub_11658(&v79);
  puts("\"><input class=\"navi_text\" type=text style=\"width:160px; display:none;\" id=\"passwd_text\" maxlength=63></td>");
  v37 = sub_134F4(1148, v36);
  printf(
    "<td class=wansetup_main_td><input type=\"checkbox\" id=\"passviewid\" name=\"passviewname\" onclick=\"clicked_passvi"
    "ew(this.checked, 'passwd');\" value=\"1\">\t\t<label for=\"passviewid\">%s</label></td>",
    v37);
  printf("</tr>");
  printf(
    "<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">\t\t<td class=\"wansetup_main_td\" cols"
    "pan=\"3\"></td></tr>",
    "FFFFFF");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v39 = sub_134F4(216, v38);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v39);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_ifconfig((int)&v96, (int)&v95, (int)&v94);
  sub_1F698((int)"pppoeip", &v95, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v41 = sub_134F4(907, v40);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v41);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"pppoesm", &v94, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v43 = sub_134F4(345, v42);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v43);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_default_gateway(&v96, &v93);
  if ( !strncmp((const char *)&v93, "ppp", 3u) )
    sf_strncpy(&v93, &v95, 20);
  sub_1F698((int)"pppoegw", &v93, 1, 1);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  get_dns_shadow(&v96, "pppoe", &v92, &v91);
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v45 = sub_134F4(227, v44);
  printf("<td class=\"wansetup_main_td\"><span class=\"wansetup_main_p\">%s</span>\n", v45);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)&unk_67A3B, &v92, 1, 0);
  puts((const char *)&unk_67572);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v47 = sub_134F4(874, v46);
  printf("<td class=\"wansetup_main_td\"><span class=\"wansetup_main_p\">%s</span>\n", v47);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"sdns_pppoe", &v91, 1, 0);
  puts("</td>");
  puts("<td class=\"wansetup_main_td\">");
  if ( get_manual_dns_flag(&v96, "pppoe") )
    v48 = "checked";
  else
    v48 = "";
  printf(
    "<input type=checkbox name=\"dns_pppoe_chk\" class=navi_chk %s onclick=\"check_dns_pppoe();\" id=\"dns_pppoe_chkid\">\n",
    v48);
  v50 = sub_134F4(637, v49);
  printf("<label for=\"dns_pppoe_chkid\"><span class=\"wansetup_main_span\">%s</span></label>\n", v50);
  puts("</td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  sub_1F87C((int)"pppoe", (int)&v90, &v89, v77);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  sub_1F9DC("pppoe", v2, v83);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  printf("<td class=\"wansetup_main_td\">");
  v52 = sub_134F4(476, v51);
  printf("<span class=\"wansetup_main_p\">%s</span>", v52);
  printf("</td>");
  printf("<td class=wansetup_main_td>");
  v54 = sub_134F4(475, v53);
  printf("<span class=\"wansetup_main_span\">%s</span>", v54);
  printf("<input class=\"navi_text\" type=text name=\"lcp_echo_interval\" size=3 maxlength=3 value=\"%d\" >", v81);
  v56 = sub_134F4(878, v55);
  printf("<span style=\"display:inline-block; vertical-align:middle; margin-right:5px;\">%s</span>", v56);
  v58 = sub_134F4(474, v57);
  printf("<span style=\"display:inline-block; vertical-align:middle; margin-left:5px;\">%s</span>", v58);
  printf("<input class=\"navi_text\" type=text name=\"lcp_echo_failure\" size=3 maxlength=3 value=\"%d\" >", v82);
  printf("</td>");
  printf("<td class=wansetup_main_td>");
  if ( v80 )
    v59 = "checked";
  else
    v59 = "";
  printf(
    "<input type=checkbox class=navi_chk id=\"lcpid\" name='lcp_flag' %s onclick=\"OnCheckEnableLCP()\" value=1>\n",
    v59);
  v61 = sub_134F4(731, v60);
  printf((const char *)&unk_67D4E, v61);
  printf("</td>");
  printf("</tr>");
  printf(
    "<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">\t\t<td class=\"wansetup_main_td\" cols"
    "pan=\"3\"></td></tr>",
    "F7F7F7");
  printf("</table>");
  printf("</td></tr>");
  strcmp((const char *)&v87, "static");
  printf("<tr id=\"static\" class=\"wansetup_main_tr\" style=\"display:%s;\"><td colspan=\"3\">");
  printf("<table class=\"v3_table wansetup_main_table\" width=\"100%%\">");
  printf("<COL width=\"180\"><COL width=\"200\"><COL width=\"%%%%\">");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v63 = sub_134F4(216, v62);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v63);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_ifconfig((int)&v96, (int)&v95, (int)&v94);
  sub_1F698((int)"ip", &v95, 1, 0);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v65 = sub_134F4(907, v64);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v65);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"sm", &v94, 1, 0);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v67 = sub_134F4(345, v66);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v67);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  get_default_gateway(&v96, &v93);
  if ( !strncmp((const char *)&v93, "ppp", 3u) )
    sf_strncpy(&v93, &v95, 20);
  sub_1F698((int)"gw", &v93, 1, 0);
  puts("</td>");
  printf("<td class=\"wansetup_main_td\"></td>");
  printf("</tr>");
  get_dns_shadow(&v96, "static", &v92, &v91);
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  v69 = sub_134F4(227, v68);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v69);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)&unk_67DE2, &v92, 1, 0);
  puts((const char *)&unk_67572);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  v71 = sub_134F4(874, v70);
  printf("<td class=\"wansetup_main_td\"><span class=\"item_text wansetup_main_p\">%s</span>\n", v71);
  printf("</td>");
  puts("<td class=\"wansetup_main_td\">");
  sub_1F698((int)"sdns_static", &v91, 1, 0);
  puts((const char *)&unk_67572);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "F7F7F7");
  sub_1F87C((int)"static", (int)&v90, &v89, v77);
  printf("</tr>");
  printf("<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">", "FFFFFF");
  sub_1F9DC("static", v2, 1500);
  printf("</tr>");
  printf(
    "<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s;\">\t\t<td class=\"wansetup_main_td\" cols"
    "pan=\"3\"></td></tr>",
    "F7F7F7");
  printf("</table></td></tr>");
  printf(
    "<tr class=\"wansetup_main_tr\" height=\"24\" style=\"background-color:#%s; border-bottom:1px #CCC solid;\">",
    "FFFFFF");
  v73 = sub_134F4(635, v72);
  printf("<td class=\"wansetup_main_td\"><span class=\"wansetup_main_p\" id=\"conntitle\">%s</span></td>", v73);
  printf("<td class=\"wansetup_main_td\" colspan=\"2\" height=\"24\">\t<div style=\"width:370px; display:inline-block; *display:inline; zoom:1; vertical-align:middle; margin:0; padding:0;\">\t<p id=\"connstatus\" style=\"width:370px; display:inline-block; *display:inline; zoom:1; vertical-align:middle; margin:0; padding:0;\"></p></div>");
  v75 = sub_134F4(28, v74);
  printf(
    "<div style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle; margin:0 0 0 10px; width:70px; pa"
    "dding:0;\">\t\t<input type=\"button\" class=\"bt\" id=\"appbtn\" value=\"%s\" onclick=\"apply_wansetup('%s','%s');\""
    ">\t\t<input type=\"button\" class=\"bt\" id=\"conbtn\" value=\"\" onclick=\"apply_connection('%s','%s');\" style=\"d"
    "isplay:none;\"></div>\n",
    v75,
    v2,
    &v96,
    v2,
    &v96);
  printf("</td></tr>");
  puts("</form>");
  printf("<form method=\"post\" name=\"backup_wansetup\">");
  return printf("</form>");
}



int __fastcall sub_20A4C(int a1)
{
  int v1; // r5@1
  int v2; // r1@3
  int v3; // r0@3
  int v4; // r1@3
  int v5; // r0@3
  int v6; // r0@3
  int v7; // r0@4
  int v8; // r0@4
  int v9; // r0@7
  int v10; // r0@7
  int v11; // r0@10
  int v12; // r0@12
  int v13; // r0@12
  int v15; // [sp+0h] [bp-38h]@3
  char dest; // [sp+14h] [bp-24h]@1

  v1 = a1;
  strcpy(&dest, "");
  if ( !get_value(v1, "wan", &dest, 20) )
    strcpy(&dest, "wan1");
  puts("<script language=JavaScript>");
  puts("<!--");
  puts("function CheckNetworkConfig()");
  puts("{");
  get_netaddr("br0", &v15);
  printf("\tif(GetNetworkAddress('ip','sm')==\"%s\")\n", &v15);
  v3 = sub_134F4(659, v2);
  printf((const char *)&unk_681C2, v3);
  printf("\telse if(GetNetworkAddress('gw','sm')==\"%s\")\n", &v15);
  v5 = sub_134F4(658, v4);
  printf((const char *)&unk_681C2, v5);
  puts(" \telse");
  puts("\t{");
  puts("\t\treturn 1;");
  puts("\t}");
  puts("\treturn 0;");
  puts("}");
  puts("-->");
  puts("</script>");
  puts("<style type=\"text/css\">");
  puts(".wansetup_main_table {");
  puts("\tborder-collapse:collapse; padding:0 0 0 0; margin:0 0 0 0;");
  puts("\ttable-layout:fixed;");
  puts("}");
  puts(".wansetup_main_tr {");
  puts("\tborder:0 0 0 0; padding:0 0 0 0;");
  puts("}");
  puts(".wansetup_main_td {");
  puts("\tpadding:0 0 0 0; font-size:12px;");
  puts("\tvertical-align:middle;");
  puts("}");
  puts(".wansetup_main_p {");
  puts("\tpadding-left:5px; display:inline-block;");
  puts("\tvertical-align:middle;");
  puts("}");
  puts(".wansetup_main_span {");
  puts("\tdisplay:inline-block; vertical-align:middle;");
  puts("}");
  puts(".wansetup_main_button {");
  puts("\tpadding:0 1 0 1; margin:0 0 0 0; font-size:12px;");
  puts("\tvertical-align:middle;");
  puts("}");
  puts(".wansetup_main_td input[type=checkbox], .wansetup_main_td input[type=radio] {");
  puts("display:inline-block; vertical-align:middle;");
  puts("}");
  printf("input[type=\"text\"] {border:1px #CCC solid;}");
  printf("input[type=\"password\"] {border:1px #CCC solid;}");
  printf("input[type=\"checkbox\"], input[type=\"radio\"], label, span, td {cursor:default;}");
  v6 = printf("</style>");
  if ( is_mobile_agent(v6) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    v7 = printf("<iframe name=\"hiddenwansetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenwansetup\" \t\t\tframeborder=no width=0 height=0 align=center scrolling=no></iframe>");
    v8 = sub_12770(v7);
  }
  else
  {
    v8 = printf("<iframe name=\"hiddenwansetup_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenwansetup\" \t\t\tframeborder=no width=0 height=0 align=center scrolling=no></iframe>");
  }
  if ( is_mobile_agent(v8) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    v9 = printf(
           "<iframe name=\"hiddenwanstatus_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenwanstatus&wan=%s\" \t\t\tf"
           "rameborder=no width=0 height=0 align=center scrolling=no></iframe>",
           &dest);
    v10 = sub_12770(v9);
  }
  else
  {
    v10 = printf(
            "<iframe name=\"hiddenwanstatus_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=hiddenwanstatus&wan=%s\" \t\t\t"
            "frameborder=no width=0 height=0 align=center scrolling=no></iframe>",
            &dest);
  }
  if ( is_mobile_agent(v10) )
  {
    sub_12790("0", "0", "display:inline-block; *display:inline; zoom:1;");
    v11 = printf("<iframe name=\"hiddenmacsearch_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=netconfmacsearch\" \t\t\tframeborder=no width=0 height=0 align=center scrolling=no></iframe>");
    sub_12770(v11);
  }
  else
  {
    printf("<iframe name=\"hiddenmacsearch_iframe\" src=\"timepro.cgi?tmenu=iframe&smenu=netconfmacsearch\" \t\t\tframeborder=no width=0 height=0 align=center scrolling=no></iframe>");
  }
  printf("<table class=\"v3_table wansetup_main_table\" width=\"100%%\">\n");
  sub_1FB50(v1, (int)&dest);
  sub_1F610((int)&dest);
  printf("</table>");
  printf("<script>");
  puts("init_checkform();");
  printf("</script>");
  printf("<DIV id=\"%s\" style=\"display:none;\">", "apply_mask");
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:536px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:231px; top:198px; width:180px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"180\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v12 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v13 = sub_126C4(v12);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v13);
  printf("</SPAN></td>");
  printf("<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:middle; display:block; text-align:center;\" id=\"wansetup_div_msg\">\n");
  printf("</SPAN></td>");
  printf((const char *)&unk_60F0E);
  printf("<DIV id=\"%s\" style=\"display:none;\">", "macsearch_mask");
  printf(
    "<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:536px; z-index:10; background-color:#ffffff; "
    "                opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\" "
    "\t\tonclick=\"UnMaskIt(document,'%s');\">\n",
    "macsearch_mask");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:151px; top:128px; width:340px; height:210px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888; overflow:hidden;\" id=\"searchmaclist\">");
  return printf((const char *)&unk_60F1B);
}



int __fastcall sub_20EC4(int a1, int a2)
{
  int v2; // r4@1
  int v3; // r7@3
  int v4; // r6@3
  void *v5; // r8@3
  void *v6; // r5@3
  int v7; // r10@3
  int v8; // r1@6
  int v9; // r0@6
  int v10; // r1@6
  int v11; // r0@6
  int v12; // r1@14
  int v13; // r0@14
  int v15; // [sp+0h] [bp-40h]@2
  char v16; // [sp+10h] [bp-30h]@1

  v2 = a2;
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"netconf_macsearchiframe\">");
  printf("<input type=\"hidden\" name=\"tmenu\" value=\"iframe\">");
  printf("<input type=\"hidden\" name=\"smenu\" value=\"netconfmacsearch\">");
  printf("<input type=\"hidden\" name=\"inputprefix\" value=\"\">");
  printf("<input type=\"hidden\" name=\"act\" value=\"\">");
  printf("</form>");
  printf("</BODY>");
  printf("<script>");
  if ( get_value_post(v2, "act", &v16, 16) && get_value_post(v2, "inputprefix", &v15, 16) )
  {
    puts("function MakeMacAddrTable()");
    puts("{");
    puts("var obj = parent.document.getElementById('searchmaclist');");
    puts("var HTMLStr = '<div style=\\\"display:block; width:340px; height:24px;\\\">\t\t\t<table class=\\\"wansetup_main_table\\\" style=\\\"width:340px; height:24px;\\\">';");
    v3 = 0;
    v4 = 0;
    v5 = malloc(0xBC00u);
    memset(v5, 0, 0xBC00u);
    v6 = v5;
    v7 = get_hostinfo_from_arp("br0", 256, v5);
    while ( v3 < v7 )
    {
      if ( strcmp((const char *)v6 + 148, "00:00:00:00:00:00") )
      {
        convert_mac((char *)v6 + 148);
        if ( !v4 )
        {
          printf("HTMLStr += '<tr class=\\\"wansetup_main_tr\\\" height=\\\"24\\\">';");
          v9 = sub_134F4(783, v8);
          printf(
            "HTMLStr += '<td class=\\\"wansetup_main_td\\\" \t\t\t\t\tstyle=\\\"width:169px; background-color:#EEEEEE; bo"
            "rder:1px #ccc solid;\\\">\t\t\t\t\t<span class=\\\"wansetup_main_span\\\" style=\\\"text-align:center; width"
            ":100%%;\\\">%s</span></td>';",
            v9);
          v11 = sub_134F4(782, v10);
          printf(
            "HTMLStr += '<td class=\\\"wansetup_main_td\\\" \t\t\t\t\tstyle=\\\"width:169px; background-color:#EEEEEE; bo"
            "rder:1px #ccc solid;\\\">\t\t\t\t\t<span class=\\\"wansetup_main_span\\\" style=\\\"text-align:center; width"
            ":100%%;\\\">%s</span></td>';",
            v11);
          printf("HTMLStr += '</tr>';");
          printf("HTMLStr += '</table></div><div \t\t\tstyle=\\\"display:block; width:340px; max-height:186px; height:186px; overflow:auto; overflow-x:hidden; -ms-overflow-x:hidden;\\\">\t\t\t\t\t<table class=\\\"wansetup_main_table\\\" style=\\\"width:340px;\\\">';");
        }
        printf(
          "HTMLStr += '<tr class=\\\"wansetup_main_tr\\\" height=\\\"24\\\" style=\"cursor:pointer;\"\t\t\t\tonclick=\\\""
          "SelectMacFromPopup(\\'%s\\', \\'%s\\');\\\" onmouseover=\\\"ChangeToOverColor(this);\\\" onmouseout=\\\"Change"
          "ToOutColor(this);\\\">';",
          &v15,
          (char *)v6 + 148);
        printf(
          "HTMLStr += '<td class=\\\"wansetup_main_td\\\" style=\\\"border:1px #ccc solid;\\\">\t\t\t\t<span class=\\\"wa"
          "nsetup_main_span\\\" style=\\\"margin-left:5px; min-width:163px;\\\">%s</a></td>';",
          (char *)v6 + 148);
        if ( *(_BYTE *)v6 )
          printf(
            "HTMLStr += '<td class=\\\"wansetup_main_td\\\" style=\\\"border:1px #ccc solid;\\\">\t\t\t\t\t<span class=\\"
            "\"wansetup_main_span\\\" style=\\\"margin-left:5px; min-width:163px;\\\">%s(%s)</span></td>';",
            (char *)v6 + 128,
            v6);
        else
          printf(
            "HTMLStr += '<td class=\\\"wansetup_main_td\\\" style=\\\"border:1px #ccc solid;\\\">\t\t\t\t\t<span class=\\"
            "\"wansetup_main_span\\\" style=\\\"margin-left:5px; min-width:163px;\\\">%s</span></td>';",
            (char *)v6 + 128,
            v6);
        ++v4;
        printf("HTMLStr += '</tr>';");
      }
      ++v3;
      v6 = (char *)v6 + 188;
    }
    if ( !v4 )
    {
      printf("HTMLStr += '<tr class=\\\"wansetup_main_tr\\\" height=\\\"24\\\">';", "00:00:00:00:00:00");
      v13 = sub_134F4(784, v12);
      printf(
        "HTMLStr += '<td class=\\\"wansetup_main_td\\\" colspan=\\\"2\\\" style=\\\"background-color:#EEEEEE;\\\">\t\t\t\t"
        "<span class=\\\"wansetup_main_span\\\">%s</span></td>';",
        v13);
      printf("HTMLStr += '</tr>';");
    }
    free(v5);
    puts("HTMLStr += '</table></div>';");
    puts("obj.innerHTML = HTMLStr;");
    puts("}");
    printf("MakeMacAddrTable();");
  }
  return printf("</script>");
}



int __fastcall sub_21164(int a1)
{
  int v1; // r4@1
  int result; // r0@1
  int v3; // r0@2
  const char *v4; // r1@2
  int v5; // r0@8
  char v6; // [sp+Ch] [bp-18Ch]@5
  char dest; // [sp+10Ch] [bp-8Ch]@4
  char v8; // [sp+14Ch] [bp-4Ch]@1
  char v9; // [sp+16Ch] [bp-2Ch]@2

  v1 = a1;
  result = get_value_post(a1, "act", &v8, 32);
  if ( result )
  {
    get_value_post(v1, "wan", &v9, 20);
    v3 = strcmp(&v9, "wan2");
    v4 = "eth3";
    if ( v3 )
      v4 = "eth1";
    strcpy(&dest, v4);
    if ( !strcmp(&v8, "connect") )
    {
      set_wansetup_status(&v9, 1);
      snprintf2(&v6, 256, "%s(%s)", "@{40}", &v9);
      syslog_msg(1, &v6);
      stop_wan(&v9);
    }
    else if ( !strcmp(&v8, "disconnect") )
    {
      snprintf2(&v6, 256, "%s(%s)", "@{41}", &v9);
      syslog_msg(1, &v6);
      set_wansetup_status(&v9, 0);
      stop_wan(&v9);
      set_ifconfig(&dest);
    }
    v5 = istatus_remove_status_tag("lanwan_samenetwork");
    result = signal_update(v5);
  }
  return result;
}



int __fastcall sub_212C4(int a1, int a2)
{
  int v2; // r4@1
  __int16 *v3; // r8@1
  int result; // r0@2
  int v5; // r1@6
  int v6; // r0@7
  int v7; // r0@12
  char *v8; // r4@15
  int v9; // r0@16
  char *v10; // r6@24
  int v11; // r1@24
  const char *v12; // r0@24
  int v13; // r5@24
  int v14; // r1@24
  const char *v15; // r0@25
  const char *v16; // r1@29
  char *v17; // r0@29
  int v18; // r1@33
  const char *v19; // r0@33
  int v20; // r1@37
  int v21; // r0@38
  int v22; // r1@40
  __int16 *v23; // r0@40
  int v24; // r1@42
  int v25; // r0@43
  __int16 v26; // [sp+2h] [bp-336h]@4
  __int16 v27; // [sp+202h] [bp-136h]@34
  __int16 v28; // [sp+242h] [bp-F6h]@37
  __int16 v29; // [sp+262h] [bp-D6h]@36
  __int16 v30; // [sp+282h] [bp-B6h]@2
  __int16 v31; // [sp+2A2h] [bp-96h]@36
  __int16 v32; // [sp+2B6h] [bp-82h]@36
  __int16 v33; // [sp+2CAh] [bp-6Eh]@4
  __int16 v34; // [sp+2DEh] [bp-5Ah]@4
  char v35; // [sp+2F2h] [bp-46h]@4
  __int16 v36; // [sp+306h] [bp-32h]@4
  __int16 v37; // [sp+316h] [bp-22h]@4

  v2 = a2;
  v3 = (__int16 *)get_pvalue(a1, "wan");
  if ( !v3 )
  {
    result = get_value_post(v2, "wan", &v30, 32);
    if ( !result )
      return result;
    v3 = &v30;
  }
  get_wan_type(v3, &v36);
  get_wan_hw_ifname(v3, &v37);
  memset(&v26, 0, 0x200u);
  get_wan_ipinfo(v3, &v35, &v34, &v33);
  if ( !strcmp((const char *)&v36, "pppoe") )
    sf_strncpy(&v33, &v35, 20);
  if ( !get_wansetup_status(v3) )
  {
    v6 = 393;
LABEL_30:
    v16 = (const char *)sub_134F4(v6, v5);
    v17 = (char *)&v26;
    goto LABEL_31;
  }
  if ( !strcmp((const char *)&v36, "pppoe") || !strcmp((const char *)&v36, "pptp") )
  {
    if ( get_idle_timeout(&v37) || !get_wansetup_status(v3) )
    {
      v6 = 1047;
      goto LABEL_30;
    }
    v7 = get_pppoe_status(v3);
    if ( !v7 )
    {
      v6 = 390;
      goto LABEL_30;
    }
    if ( v7 == 4 )
    {
      v8 = (char *)&v26;
      if ( !v35 )
      {
        v9 = 1044;
LABEL_29:
        v16 = (const char *)sub_134F4(v9, v5);
        v17 = v8;
LABEL_31:
        strcat(v17, v16);
        goto LABEL_32;
      }
LABEL_23:
      v9 = 1045;
      goto LABEL_29;
    }
    if ( v7 == 6 )
    {
      v6 = 1048;
      goto LABEL_30;
    }
  }
  else
  {
    v8 = (char *)&v26;
    if ( v35 )
      goto LABEL_23;
    v10 = (char *)&v26 + strlen((const char *)&v26);
    v12 = (const char *)sub_134F4(1049, v11);
    v13 = sprintf(v10, v12);
    if ( istatus_get_intvalue_direct("lanwan_samenetwork") == 1 )
    {
      v15 = (const char *)sub_134F4(732, v14);
      sprintf(&v10[v13], v15, "JavaScript:MovePagetoMain(\\'netconf\\',\\'lansetup\\');");
      goto LABEL_32;
    }
    if ( istatus_get_intvalue_direct("privateip") == 1 && get_dhclient_block_private_ip(&v37) )
    {
      v9 = 1052;
      goto LABEL_29;
    }
  }
LABEL_32:
  if ( !get_wan_link(v3) )
  {
    strcpy((char *)&v26, "");
    v19 = (const char *)sub_134F4(120, v18);
    strcat((char *)&v26, v19);
  }
  memset(&v27, 0, 0x40u);
  if ( get_idle_timeout(&v37) || !get_wansetup_status(v3) )
  {
    if ( strcmp((const char *)&v36, "static") )
    {
      sf_strncpy(&v28, "connect", 32);
      if ( !strcmp((const char *)&v36, "dynamic") )
        v25 = 655;
      else
        v25 = 1053;
      v22 = sub_134F4(v25, v24);
      v23 = &v27;
      goto LABEL_46;
    }
  }
  else
  {
    get_dns_shadow(&v37, &v36, &v32, &v31);
    get_hwaddr_kernel(&v37, &v29);
    convert_mac(&v29);
    if ( strcmp((const char *)&v36, "static") )
    {
      sf_strncpy(&v28, "disconnect", 32);
      if ( !strcmp((const char *)&v36, "dynamic") )
        v21 = 654;
      else
        v21 = 1046;
      v22 = sub_134F4(v21, v20);
      v23 = &v27;
LABEL_46:
      sf_strncpy(v23, v22, 64);
      goto LABEL_47;
    }
  }
LABEL_47:
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"waninfostatus_fm\">");
  printf("<input type=\"hidden\" name=\"tmenu\" value=\"iframe\">");
  printf("<input type=\"hidden\" name=\"smenu\" value=\"hiddenwanstatus\">");
  printf("<input type=\"hidden\" name=\"wan\" value=\"%s\">", v3);
  printf("<input type=\"hidden\" name=\"wan_type\" value=\"%s\">", &v36);
  printf("<input type=\"hidden\" name=\"fdns\" value=\"%s\">", &v32);
  printf("<input type=\"hidden\" name=\"sdns\" value=\"%s\">", &v31);
  printf("<input type=\"hidden\" name=\"ip\" value=\"%s\">", &v35);
  printf("<input type=\"hidden\" name=\"sm\" value=\"%s\">", &v34);
  printf("<input type=\"hidden\" name=\"gw\" value=\"%s\">", &v33);
  printf("<input type=\"hidden\" name=\"buttonact\" value=\"%s\">", &v28);
  printf("</form>");
  printf("</BODY>");
  printf("<script>");
  printf("parent.document.getElementById('connstatus').innerHTML = '%s';\n", &v26);
  printf("parent.document.getElementById('conbtn').value = '%s';\n", &v27);
  puts("EnableObj(parent.document.getElementById('conbtn'));");
  puts("if(parent.window.footerbtn_view_control)\tparent.window.footerbtn_view_control(parent.document);");
  puts("if(parent.window.update_addrs)\t\t\tparent.window.update_addrs(document, parent.document);");
  puts("setTimeout(function(){document.waninfostatus_fm.submit(); \t\tif(parent.window.submitted){parent.window.submitted = false; UnMaskIt(parent.document,'apply_mask');}},3000);");
  return printf("</script>");
}



int __fastcall sub_21820(int a1, const char *a2, int a3)
{
  const char *v3; // r5@1
  int v4; // r7@1
  int v5; // r6@1
  char v7; // [sp+4h] [bp-17Ch]@2
  char v8; // [sp+84h] [bp-FCh]@2
  char v9; // [sp+104h] [bp-7Ch]@2
  char v10; // [sp+124h] [bp-5Ch]@7
  char s2; // [sp+138h] [bp-48h]@2
  char dest; // [sp+14Ch] [bp-34h]@4

  v3 = a2;
  v4 = a1;
  v5 = a3;
  if ( !strcmp(a2, "eth1") )
  {
    snprintf2(&v8, 128, "hw_conf_%s", v5);
    snprintf2(&v7, 128, "hw_%s", v5);
    get_hwaddr_kernel(v3, &s2);
    if ( get_value_post(v4, &v8, &v9, 32) && !strcmp(&v9, "on") )
    {
      strcpy(&dest, "");
      get_hw_value_post(v4, &v7, &dest);
      if ( !check_invalid_hwaddr(&dest) && strcmp(&dest, &s2) )
      {
        set_hwaddr_kernel(v3, &dest, 1);
        set_hwaddr_cloned(v3, &dest);
      }
    }
    else
    {
      get_hwaddr_org(v3, &v10);
      set_hwaddr_cloned(v3, 0);
      if ( strcmp(&v10, &s2) )
        set_hwaddr_kernel(v3, &v10, 1);
    }
  }
  return 0;
}



int __fastcall sub_21980(int a1, int a2, const char *a3)
{
  int v3; // r9@1
  const char *v4; // r4@1
  int v5; // r6@1
  int v6; // r5@1
  char v8; // [sp+Ch] [bp-1C4h]@4
  char v9; // [sp+8Ch] [bp-144h]@4
  char v10; // [sp+10Ch] [bp-C4h]@3
  char v11; // [sp+14Ch] [bp-84h]@4
  char v12; // [sp+18Ch] [bp-44h]@4
  int v13; // [sp+1ACh] [bp-24h]@9

  v3 = a1;
  v4 = a3;
  v5 = a2;
  v6 = hwinfo_get_mtu(a3);
  if ( !strcmp(v4, "pppoe") || !strcmp(v4, "pptp") )
    get_pppoe_ifname(v5, &v10);
  get_wan_hw_ifname(v5, &v11);
  snprintf2(&v9, 128, "mtu.%s.%s", v4, &v11);
  snprintf2(&v8, 128, "mtu.%s.%s.check", v4, &v11);
  if ( get_value_post(v3, &v8, &v12, 32) && !strcmp(&v12, "on") )
  {
    if ( get_intvalue_post(v3, &v9, &v13) )
    {
      iconfig_set_intvalue_direct(&v8, 1);
      v6 = get_mtu_value(&v11, 1);
      if ( v6 != v13 )
      {
        iconfig_set_intvalue_direct(&v9, v13);
        if ( strcmp(v4, "pppoe") && strcmp(v4, "pptp") )
          set_mtu_value(&v11, v13);
        v6 = v13;
      }
    }
  }
  else
  {
    iconfig_set_intvalue_direct(&v8, 0);
    if ( strcmp(v4, "pppoe") && strcmp(v4, "pptp") )
      set_mtu_value(&v11, v6);
  }
  return v6;
}



int __fastcall sub_21B34(int a1)
{
  int v1; // r8@1
  int result; // r0@1
  const char *v3; // r0@3
  int v4; // r0@12
  int v5; // r1@15
  __int16 *v6; // r0@16
  int v7; // r0@31
  int v8; // r0@33
  int v9; // r0@33
  int v10; // r0@36
  int v11; // r0@36
  int v12; // r0@36
  int v13; // [sp+8h] [bp+0h]@1
  char v14; // [sp+208h] [bp+200h]@22
  char v15; // [sp+288h] [bp+280h]@24
  int v16; // [sp+330h] [bp+328h]@24
  char v17; // [sp+334h] [bp+32Ch]@26
  char v18; // [sp+338h] [bp+330h]@26
  int v19; // [sp+340h] [bp+338h]@24
  __int16 v20; // [sp+346h] [bp+33Eh]@28
  __int16 v21; // [sp+3C6h] [bp+3BEh]@4
  __int16 v22; // [sp+406h] [bp+3FEh]@28
  __int16 v23; // [sp+426h] [bp+41Eh]@28
  __int16 v24; // [sp+446h] [bp+43Eh]@28
  __int16 v25; // [sp+466h] [bp+45Eh]@33
  __int16 v26; // [sp+47Ah] [bp+472h]@33
  __int16 v27; // [sp+48Eh] [bp+486h]@6
  __int16 v28; // [sp+4A2h] [bp+49Ah]@6
  __int16 v29; // [sp+4B6h] [bp+4AEh]@6
  __int16 v30; // [sp+4CAh] [bp+4C2h]@2
  __int16 v31; // [sp+4DEh] [bp+4D6h]@4

  v1 = a1;
  result = get_value_post(a1, "act", &v13, 512);
  if ( result )
  {
    if ( !get_value_post(v1, "wan", &v30, 20) )
    {
      v3 = "No WAN name is specified. Debug it..";
      return puts(v3);
    }
    get_wan_hw_ifname(&v30, &v31);
    set_wansetup_status(&v30, 1);
    result = get_value_post(v1, "wan_type", &v21, 64);
    if ( !result )
      return result;
    ((void (*)(void))signal_toggle)();
    stop_wan(&v30);
    set_wan_type(&v30, &v21);
    if ( !strcmp((const char *)&v21, "static") )
    {
      strcpy((char *)&v29, "");
      get_ip_value_post(v1, "ip", &v29);
      strcpy((char *)&v28, "");
      get_ip_value_post(v1, "sm", &v28);
      strcpy((char *)&v27, "");
      get_ip_value_post(v1, "gw", &v27);
      set_wan_ipconfig(&v31, &v29, &v28, &v27);
      sub_21820(v1, (const char *)&v31, (int)&v21);
      set_ifconfig(&v31);
      if ( !sysconf_nat_get(1) )
        make_virtual_host_page(&v29);
      if ( check_default_gateway(&v27, &v29, &v28) )
      {
        set_default_gateway(&v31, 0);
      }
      else
      {
        set_default_gateway("br0", 0);
        if ( set_default_gateway(&v31, &v27) )
          set_default_gateway2(&v31, &v29, &v28, &v27);
      }
      v4 = sub_21980(v1, (int)&v30, (const char *)&v21);
      signal_wan(v4);
    }
    else if ( !strcmp((const char *)&v21, "dynamic") )
    {
      set_ifconfig(&v31);
      set_wan_ipconfig(&v31, "0.0.0.0", "255.255.255.0", 0);
      if ( !get_value_post(v1, "allow_private", &v13, 512) || (v5 = strcmp((const char *)&v13, "on")) != 0 )
      {
        v6 = &v31;
        v5 = 1;
      }
      else
      {
        v6 = &v31;
      }
      set_dhclient_block_private_ip(v6, v5);
      set_dhcp_auto_restart(&v31, 1);
      sub_21820(v1, (const char *)&v31, (int)&v21);
      sub_21980(v1, (int)&v30, (const char *)&v21);
    }
    else if ( !strcmp((const char *)&v21, "pppoe") )
    {
      if ( get_pppoe_status(&v30) == 7 )
        set_pppoe_status(&v30, 0);
      set_ifconfig(&v31);
      set_wan_ipconfig(&v31, "0.0.0.0", "255.255.255.0", 0);
      read_pppoe_option(&v30, &v14);
      get_value_post(v1, "userid", &v14, 128);
      if ( check_unpermitted_chars(&v14) )
        strcpy(&v14, "");
      get_value_post(v1, "passwd", &v15, 128);
      sub_21820(v1, (const char *)&v31, (int)&v21);
      v19 = sub_21980(v1, (int)&v30, (const char *)&v21);
      if ( get_intvalue_post(v1, "lcp_flag", &v16) )
      {
        get_intvalue_post(v1, "lcp_echo_interval", &v17);
        get_intvalue_post(v1, "lcp_echo_failure", &v18);
      }
      else
      {
        v16 = 0;
      }
      save_pppoe_option(&v30, &v14);
    }
    snprintf2(&v20, 128, "dns_%s_chk", &v21);
    snprintf2(&v23, 32, "fdns_%s", &v21);
    snprintf2(&v22, 32, "sdns_%s", &v21);
    if ( get_value_post(v1, &v20, &v24, 32) && !strcmp((const char *)&v24, "on")
      || !strcmp((const char *)&v21, "static") )
    {
      v7 = strcmp((const char *)&v21, "static");
      if ( v7 && !check_valid_account(v7) )
        goto LABEL_36;
      strcpy((char *)&v26, "");
      strcpy((char *)&v25, "");
      get_ip_value_post(v1, &v23, &v26);
      get_ip_value_post(v1, &v22, &v25);
      set_autodns(0);
      dhcpd_set_dns(&v26, &v25);
      set_manual_dns_flag(&v31, &v21, 1);
      v8 = set_dns_shadow(&v31, &v21, &v26, &v25);
      v9 = get_remote_addr(v8);
      syslog_msg(1, "@{57}", v9, &v26, &v25);
    }
    else
    {
      set_autodns(1);
      set_manual_dns_flag(&v31, &v21, 0);
    }
    set_system_dns(&v30);
LABEL_36:
    v10 = istatus_remove_status_tag("lanwan_samenetwork");
    v11 = signal_toggle(v10);
    v12 = signal_update(v11);
    signal_save(v12);
    puts("<script language=JavaScript>");
    v3 = "</script>";
    return puts(v3);
  }
  return result;
}



int __fastcall sub_2218C(int a1, int a2)
{
  int v2; // r4@1
  char v4; // [sp+0h] [bp-30h]@1

  v2 = a2;
  memset(&v4, 0, 0x20u);
  if ( get_value_post(v2, "act", &v4, 32) )
  {
    if ( !strcmp(&v4, "connect") || !strcmp(&v4, "disconnect") )
      sub_21164(v2);
    else
      sub_21B34(v2);
  }
  printf("<BODY style=\"display:block; vertical-align:middle; padding:0 0 0 0; margin:0 0 0 0; border:0 0 0 0; overflow:hidden;\">");
  printf("<form action=\"timepro.cgi\" method=\"post\" name=\"netconf_wansetup\">");
  printf("</form>");
  printf("</BODY>");
  printf("<script>");
  if ( v4 )
    printf("parent.window.submitted = true;");
  return printf("</script>");
}



int sub_22278()
{
  int v0; // r4@1

  printf("<style>");
  printf("body { margin: 0; }");
  printf("form { margin: 0; }");
  printf("tr { height: 24px; }");
  printf(".selected { background-color: #CCCCFF !important; }");
  printf(".highlight { background-color: #E8E8E8 !important; }");
  printf(".highlight_selected { background-color: #BBBBFF !important; }");
  printf("</style>");
  sub_133E4("sysconf", "syslog");
  printf((const char *)&unk_6966E);
  printf("<table cellspacing=0px cellpadding=0px style='width:100%%;'>\n");
  v0 = 0;
  do
  {
    ++v0;
    printf("<tr style='background-color:%s;'><td colspan=2><p name=blanktr>&nbsp;</p></td></tr>");
  }
  while ( v0 != 14 );
  printf("</table>");
  return printf("<iframe name=\"sysconf_syslog_log_status\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_syslog_log_status\" frameborder=no style='display:none;'></iframe>");
}



int sub_22358()
{
  int v0; // r1@1
  int v1; // r0@1

  printf("<tr style='background-color: #EEE; height: 24px;'><td>");
  v1 = sub_134F4(1005, v0);
  printf("<b style='padding-left: 5px;'>%s</b>", v1);
  printf("</td></tr>");
  printf("<tr style='border-top: 1px solid #CCC;'><td>");
  printf("<iframe name=\"sysconf_syslog_setup\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_syslog_setup\" frameborder=no style='width:100%%; height:120px;'></iframe>");
  return printf("</td></tr>");
}



int sub_223B8()
{
  printf("<style>");
  printf("body { margin: 0; background-color: #EEE; }");
  printf("form { margin: 0; }");
  printf("tr { height: 24px; }");
  printf("</style>");
  sub_133E4("sysconf", "syslog");
  puts("<form method=post action=timepro.cgi name=syslog_fm>");
  printf("<table id='sysconf_syslog_setup_table' cellspacing=0px cellpadding=0px style='width:100%%; padding-left: 5px; border-bottom: 1px solid #CCC;'>\n");
  printf("</table>");
  printf("<iframe name=\"sysconf_syslog_setup_status\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_syslog_setup_status\" frameborder=no style='display:none;'></iframe>");
  return printf("</form>");
}



int sub_2244C()
{
  int v0; // r1@1
  int v1; // r0@1
  int v2; // r1@1
  int v3; // r0@1
  int v4; // r0@1
  int v5; // r4@1
  int v6; // r1@1
  int v7; // r0@1

  printf("<tr><td>");
  puts("<table cellspacing=0px cellpadding=0px style='border-bottom: 1px solid #CCC; height: 24px; background-color: #EEE;'>");
  printf("<colgroup><col width=158px><col width=402px><col width=81px></colgroup>");
  printf("<tr>");
  v1 = sub_134F4(1003, v0);
  printf("<td><span style='padding-left: 5px;'>%s</span></td>", v1);
  v3 = sub_134F4(998, v2);
  printf("<td><span>%s</span></td>", v3);
  v4 = puts("<td align=right>");
  v5 = sub_126C4(v4);
  v7 = sub_134F4(1000, v6);
  printf(
    "<span name=rmlog_bt style='margin-right: 20px; cursor:pointer; width: 65px;' onclick=\"RemoveLog();\"><img src='/%s/"
    "minus_icon.gif' style='margin: 1px;'>%s</span>",
    v5,
    v7);
  printf("</td>");
  printf("</tr>");
  printf("</table>");
  printf("</td></tr>");
  printf("<tr><td>");
  printf("<iframe name=\"sysconf_syslog_log\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_syslog_log\" scrolling=yes frameborder=no style='width:100%%; height:336px; border-bottom: 1px solid #CCC;'></iframe>");
  printf("<iframe name=\"sysconf_syslog_log_clear\" src=\"timepro.cgi?tmenu=iframe&smenu=sysconf_syslog_log_clear\" frameborder=no style='display:none;'></iframe>");
  return printf("</td></tr>");
}




int __fastcall sub_2254C(int a1, int a2)
{
  int v2; // r5@1
  int v3; // r0@1
  int v4; // r0@1

  v2 = a2;
  printf("<DIV id=\"%s\" style=\"display:none;\">", a1);
  puts("<DIV style=\"position:absolute; left:0px; top:0px; width:642px; height:535px; z-index:10; background-color:#ffffff;                 opacity:0.5; -moz-opacity:0.5; -khtml-opacity:0.5; -webkit-opacity:0.5; filter:alpha(opacity=50);\">");
  printf("</DIV>");
  puts("<DIV style=\"position:absolute; left:231px; top:198px; width:180px; height:70px; z-index:100; background-color:#ffffff;                 opacity:1; -moz-opacity:1; -khtml-opacity:1; -webkit-opacity:1; filter:alpha(opacity=100); border:1px #CCC solid;                 box-shadow:5px 5px 20px #888888;\">");
  puts("<table width=\"180\" height=\"70\">");
  printf("<tr><td width=\"20%%\" height=\"100%%\" align=\"center\" valign=\"middle\">\n");
  v3 = puts("<SPAN style=\"vertical-align:middle; display:block; text-align:center;\">");
  v4 = sub_126C4(v3);
  printf(
    "<img src=\"/%s/apply_ani.gif\" style=\"display:inline-block; *display:inline; zoom:1; vertical-align:middle;\">",
    v4);
  printf("</SPAN></td>");
  printf(
    "<td width=\"80%%\" height=\"100%%\" align=\"center\" valign=\"middle\">                <SPAN style=\"vertical-align:"
    "middle; display:block; text-align:center;\">%s\n",
    v2);
  printf("</SPAN></td>");
  return printf((const char *)&unk_60F0E);
}



int sub_225F8()
{
  int v0; // r1@1
  int v1; // r0@1

  sub_133E4("sysconf", "syslog");
  printf("<table cellspacing=0px cellpadding=0px style='width:100%%;'>\n");
  sub_2244C();
  sub_22358();
  printf("</table>");
  v1 = sub_134F4(27, v0);
  return sub_2254C((int)"apply_mask", v1);
}