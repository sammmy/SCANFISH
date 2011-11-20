#ifndef GSMESSAGEEDITOR_H
#define	GSMESSAGEEDITOR_H

class GSMessageEditor
{
public:
    GSMessageEditor();
    int gssend(unsigned int msgId, unsigned int msgDlc, unsigned char msgData);
};

#endif	/* GSMESSAGEEDITOR_H */

