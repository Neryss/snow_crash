## Level 05

We are gretted by a notification that we received a new mail!

We look through the /var/mail folder and find a `level05` containing:

`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`

If we take a look at `/usr/sbin/openarenaserver`

We can find:

```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

