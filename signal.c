
/*
 * Author : Paul May
 *
 * Free software yadda yadda
 *
 */


#include <glib.h>
#include <gmodule.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal/signal_protocol.h>
#include <unistd.h>
#include <purple.h>
#include <prpl.h>
#include <notify.h>
#include <version.h>
#include <plugin.h>
#include "purplecompat.h"
#include "glibcompat.h"

/* hash define alot of globals here */

#define VERSION "0.0.1a"
#define TITLE "Signal"
#define DESCRIPTION "a plugin for the Signal secure messenger"
#define TOOLTIP_DESCRIPTION "a plugin for the signal secure messenger"
#define PLUGIN_ID "prpl-mobilebunaglow-signalapp_plugin"
#define CONTACT "Oblong studded@shirtless.cob"
#define WEBSITE "OblongsLongOptBlog.blogger.cob"


/* one of the magic details in the tutorial */

#ifndef PURPLE_PLUGINS

#define		PURPLE_PLUGINS

#endif

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


/*
 * this function is called on plugin start 
 * returns a gbool indicating failure or sucess
 */

PurplePlugin *signalapp_plugin = NULL;


  static void
  plugin_action_test_cb (PurplePluginAction * action)
  {
          purple_notify_message (signalapp_plugin, PURPLE_NOTIFY_MSG_INFO,
                  "Plugin Actions Test", "plugact", NULL, NULL,
                  NULL);
  }


  static GList *
  plugin_actions (PurplePlugin * plugin, gpointer context)
  {
          /* some C89 (a.k.a. ANSI C) compilers will warn if any variable declaration
           * includes an initilization that calls a function.  To avoid that, we
           * generally initialize our variables first with constant values like NULL
           * or 0 and assign to them with function calls later */
          GList *list = NULL;
          PurplePluginAction *action = NULL;
  
          /* The action gets created by specifying a name to show in the UI and a
           * callback function to call. */
          action = purple_plugin_action_new ("Plugin Action Test", plugin_action_test_cb);
  
          /* libpurple requires a GList of plugin actions, even if there is only one
           * action in the list.  We append the action to a GList here. */
          list = g_list_append (list, action);
  
          /* Once the list is complete, we send it to libpurple. */
          return list;
  }


static gboolean
plugin_load(PurplePlugin *plugin)
{

	signalapp_plugin = plugin;

	return TRUE;	
}

/*
 * same as above except unload
 */

static gboolean
plugin_unload(PurplePlugin *plugin)
{
	return TRUE;
}

/*
 * same as above except emergency unload
 * destructor. this should be agressive
 */



static GList*
status_list(PurpleAccount * account)
{
	GList * types = NULL;

	PurpleStatusType *status;
	
	status = purple_status_type_new_full(PURPLE_STATUS_AVAILABLE, NULL, NULL, TRUE, TRUE, FALSE);
	types = g_list_append(types, status);

	status = purple_status_type_new_full(PURPLE_STATUS_OFFLINE, NULL, NULL, TRUE, TRUE, FALSE);
	types = g_list_append(types, status);

	return types;
}

static void
login(PurpleAccount *account)
{


}

static void
purple_close(PurpleConnection *pc)
{


}



static const char *signal_list_icon(PurpleAccount *account, PurpleBuddy *buddy)
{
	return "Signal";
}

static PurplePluginProtocolInfo prple_info = {
	
	OPT_PROTO_MAIL_CHECK,
	NULL,                   /* user_splits */
	NULL,                   /* protocol_options */
	NO_BUDDY_ICONS,    /* icon_spec */
	signal_list_icon,          /* list_icon */
	NULL,                   /* list_emblems */
	NULL,        /* status_text */
	NULL,       /* tooltip_text */
	status_list,           /* status_types */
	NULL,    /* blist_node_menu */
	NULL,                   /* chat_info */
	NULL,                   /* chat_info_defaults */
	login,              /* login */
	purple_close,              /* close */
	NULL,            /* send_im */
	NULL,                   /* set_info */
	NULL,                   /* send_typing */
	NULL,           /* get_info */
	NULL,                   /* set_status */
	NULL,                   /* set_idle */
	NULL,                   /* change_passwd */
	NULL,          /* add_buddy */
	NULL,                   /* add_buddies */
	NULL,       /* remove_buddy */
	NULL,                   /* remove_buddies */
	NULL,                   /* add_permit */
	NULL,        /* add_deny */
	NULL,                   /* rem_permit */
	NULL,                   /* rem_deny */
	NULL,                   /* set_permit_deny */
	NULL,                   /* join_chat */
	NULL,                   /* reject chat invite */
	NULL,                   /* get_chat_name */
	NULL,                   /* chat_invite */
	NULL,                   /* chat_leave */
	NULL,                   /* chat_whisper */
	NULL,                   /* chat_send */
	NULL,                   /* keepalive */
	NULL,                   /* register_user */
	NULL,                   /* get_cb_info */
	NULL,                   /* get_cb_away */
	NULL,                   /* alias_buddy */
	NULL,   /* group_buddy */
	NULL,                   /* rename_group */
	NULL,         /* buddy_free */
	NULL,                   /* convo_closed */
	NULL,/* normalize */
	NULL,                   /* set_buddy_icon */
	NULL,                   /* remove_group */
	NULL,                   /* get_cb_real_name */
	NULL,                   /* set_chat_topic */
	NULL,                   /* find_blist_chat */
	NULL,                   /* roomlist_get_list */
	NULL,                   /* roomlist_cancel */
	NULL,                   /* roomlist_expand_category */
	NULL,                   /* can_receive_file */
	NULL,                   /* send_file */
	NULL,                   /* new_xfer */
	NULL,                   /* offline_message */
	NULL,                   /* whiteboard_prpl_ops */
	NULL,                   /* send_raw */
	NULL,                   /* roomlist_room_serialize */
	NULL,                   /* unregister_user */
	NULL,                   /* send_attention */
	NULL,                   /* attention_types */
	sizeof(PurplePluginProtocolInfo), /* struct_size */
	NULL, /* get_account_text_table */
	
};


static 
PurplePluginInfo info = 
{
PURPLE_PLUGIN_MAGIC,
PURPLE_MAJOR_VERSION,
PURPLE_MINOR_VERSION,
PURPLE_PLUGIN_PROTOCOL,
NULL,
0,
NULL,
PURPLE_PRIORITY_DEFAULT,
PLUGIN_ID,
TITLE,
VERSION,
DESCRIPTION,
TOOLTIP_DESCRIPTION,
CONTACT,
WEBSITE,
plugin_load,
plugin_unload,
NULL,
NULL,
&prple_info,
NULL,
plugin_actions,
NULL,
NULL,
NULL,
NULL,
};

static void
initPlugin(PurplePlugin* plugin)
{


}


PURPLE_INIT_PLUGIN(signalapp_plugin, initPlugin, info);
