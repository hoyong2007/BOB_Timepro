
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