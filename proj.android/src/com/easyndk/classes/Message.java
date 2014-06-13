package com.easyndk.classes;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class Message {
	private int command;
	public int size;
	private ByteArrayOutputStream os = null;
	public DataOutputStream dos = null;

	private ByteArrayInputStream is = null;
	public DataInputStream dis = null;

	public Message(int command) {
		this.command = command;
		os = new ByteArrayOutputStream();
		dos = new DataOutputStream(os);
	}

	public Message(int command, byte[] data) {
		this.command = command;
		is = new ByteArrayInputStream(data);
		dis = new DataInputStream(is);
	}

	public byte[] getData() {
		return os.toByteArray();
	}

	public byte[] toByteArray() {
		int datalen = 0;
		byte[] data = null;
		byte[] bytes = null;

		try {
			if (dos != null) {
				dos.flush();
				data = os.toByteArray();
				datalen = data.length;
				dos.close();
			}
			ByteArrayOutputStream bos1 = new ByteArrayOutputStream(3 + datalen);
			DataOutputStream dos1 = new DataOutputStream(bos1);

			dos1.writeByte(command);
			dos1.writeShort(datalen);
			if (datalen > 0)
				dos1.write(data);
			bytes = bos1.toByteArray();
			dos1.close();
		} catch (IOException e) {
		}

		return bytes;
	}

	public void release() {
		try {
			if (dis != null) {
				dis.close();
			}
			if (dos != null) {
				dos.close();
			}
		} catch (IOException e) {
		}
	}

	public int getCommand() {
		return command;
	}

	public int setCommand(int cmd) {
		return command = cmd;
	}

	public DataInputStream reader() {
		return dis;

	}

	public DataOutputStream writer() {
		return dos;
	}

}
