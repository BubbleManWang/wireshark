/** @file
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef CONVERSATION_DIALOG_H
#define CONVERSATION_DIALOG_H

#include "traffic_table_dialog.h"

class ConversationDialog : public TrafficTableDialog
{
    Q_OBJECT

public:
    /** Create a new conversation window.
     *
     * @param parent Parent widget.
     * @param cf Capture file. No statistics will be calculated if this is NULL.
     * @param cli_proto_id If valid, add this protocol and bring it to the front.
     * @param filter Display filter to apply.
     */
    explicit ConversationDialog(QWidget &parent, CaptureFile &cf, int cli_proto_id = -1, const char *filter = NULL);

protected:
    void captureFileClosing();
    void captureFileClosed();

signals:
    void filterAction(QString filter, FilterAction::Action action, FilterAction::ActionType type);
    void openFollowStreamDialog(follow_type_t type, guint stream_num, guint sub_stream_num);
    void openTcpStreamGraph(int graph_type);

private:
    QPushButton *follow_bt_;
    QPushButton *graph_bt_;

    bool tcp_graph_requested_;

private slots:
    void followStream();
    void graphTcp();
    void on_buttonBox_helpRequested();
    void displayFilterSuccess(bool success);
    void tabChanged(int idx);
};

void init_conversation_table(struct register_ct* ct, const char *filter);

#endif // CONVERSATION_DIALOG_H
