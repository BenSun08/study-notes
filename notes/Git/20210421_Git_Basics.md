# Basic Concepts in Git

## 1. Getting a Git Repository

### Initialize a Repository in an Existing Directory

```bash
git init
```

 Then under the directory a folder called _.git_ is created, which contains all of the necessary repository files. However, the existing files in the directory are still not tracked. You should add a few commands:

```bash
git add .
git commit -m "initialize a repository"
```

### Cloning an Existing Repository

```bash
git clone <url> [<localDirName>]
```

## 2. Recording Changes to Repository

Any files in the work directory can be one of the two states: **tracked** or **untracked**.
_Tracked_ files are files that are in the last snapshot. They can be unmodified, modified or staged.
_Untracked_ files are any files that are not in the last snapshot or staging area.
![lifecycle](./images/lifecycle.png)

### Checking the Status of Files

```bash
git status
```

#### Short Status

```bash
git status -s
```

or

```bash
git status --short
```

#### View Staged and Unstaged Files

modified or added but not staged:

```bash
git diff
```

staged:

```bash
git diff --staged # or --cached. It's equivalent
```

### Tracking New Files/ Staging Modified Files

```bash
git add filename
```

`add` means 'add precisely this content in next commit' instead of 'add this file to the project'.

### Ignoring Files

You can edit the _.gitignore_ file to ignore the files you don't want to track.
rules:

- Blank lines and lines with `#` are ignored.
- glob works, and will be work recursively.
- start patterns with forward slash(`/`) to avoid recursion.
- end patterns with forward slash(`/`) to specify a directory.
- negate a pattern by starting with exclamation point(`!`).

### Committing Files

```bash
git commit # -m, with message inline
```

#### Skipping the Staging Area

```bash
git commit -a -m "some message" # -a, automatically stage files that already been tracked
```

### Removing File/ Moving Files

**useful trick**

```bash
git rm filename # remove file form both working tree and staging area
git rm --cached filename # remove file from staging area but keep it in working tree, and Git will not track it anymore
git mv file_from file_to # can be used to rename a file
```

## 3. Viewing the Commit History

```bash
git log
#options:
git log -p
git log --patch # show the difference introduced in each commit

git log --stat # show how many files were changed, and how many lines of codes were added or removed in each commit

git log --pretty=<oneline | short | full | fuller | format> # specify the output log format

git log --pretty=format: "%h - %an, %ar : %s"
```

| specifier | description of output |
| :-------: | :-------------------: |
|   `%h`    |      commit hash      |
|   `%an`   |      author name      |
|   `%ad`   |      author date      |
|   `%ar`   | author date(relative) |
|   `%s`    |    commit message     |

```bash
git log --graph # give a graph to show braching and merging history
```

### Limiting Log Output

```bash
git log -<n> # show the last n commits

git log --since=2.weeks # show commits since two weeks ago

git log -S function_name # show commits that add or remove function_name

git log -- path/to/file # show commits about the modification of specified directory or files
```

|        Options        |            Description            |
| :-------------------: | :-------------------------------: |
| `--since`, `--after`  | commits that after specified date |
| `--until`, `--before` |       before specified date       |
|      `--author`       |          author matches           |
|       `--grep`        |      commit message matches       |

## 4 Undoing Things

**useful trick**

```bash
git commit --amend
```

This command take your _staging area_ and use it for the commit that replaces the last commit entirely.
**Note**: this command only amend commits that are local and not pushed somewhere.

### Unstaging a Staged File

```bash
git reset HEAD <filename>
```

### Unmodifying a Modified File

```bash
git checkout -- <filename>
```

**Note**: this is dangerous since the unmodifying cannot be recovered. Remember, anything you lose that was never committed is likely never to be seen again.

### Undoing Things with git restore

recommended from Git version 2.23.0 onwards

#### Unstaging

```bash
git restore --staged <filename>
```

#### Unmodifying

```bash
git restore <filename>
```

## 5. Working with Remotes

### Showing the Remotes

```bash
git remote
git remote -v # show URLs and their corresponding shortname
```

### Adding Remote Repositories

```bash
git remote add <shortname> <url>
```

### Fetching and Pulling from Remotes

```bash
git fetch <remote>
```

This commands only downloads all the data to local repository, **It doesn't automatically merge it with the local work**.

If a local branch is set up to track a remote branch

```bash
git pull
```

can be used to fetch and automatically merge the remote branch in to current local branch.

### Pushing to Remotes

```bash
git push <remote> <branch>
```

### Inspecting a Remote

see more information about a remote repository

```bash
git remote show <remote> # it lists the URLs for the remote repository and the tracking branch information
```

### Renaming and Removing Remotes

```bash
git remote rename <oldName> <newName>
git remote remove <remote>
```

## 6. Tagging

### Listing Tags

```bash
git tag # list all tags
git tag -l [<pattern>] #list all/specified tags
git tag --list [<pattern>]
```

### Creating Tags

two types:

- lightweight tags: just a pointer to specific commit.
- annotated tags: checksummed; contain tagger information; have tagging message; stored as full objects in Git database.

#### Annotated Tags

```bash
git tag -a <tagName> [-m <taggingMessage>]
```

#### Lightweight Tags

```bash
git tag <tagName>
```

You can use `git show <tagName>` to show the specific commit. Only in annotated tags are tagger information showed.

### Tagging Later

```bash
git tag -a <tagName> <commitChecksum>
```

### Sharing Tags

```bash
git push <remote> <tagName> # push specific tag to remote repository
git push <remote> --tags # push all tags to remote repository, including annotated and lightweight tags.
git push <remote> --follow-tags # push all annotated tags
```

### Deleting Tags

```bash
git tag -d <tagName> # delete local tag

git push <remote> --delete <tagName> # delete remote tag
git push <remote> :refs/tags/<tagName>
```

### Checking out Tags

```bash
git checkout <tagName>
```

this command let you in _'detached HEAD' state_. Where if you makes changes and then create a commit, the tag will not change, but the commit is not belong to any branches and unreachable, except by commit hash. If you need to make a change, you will need to create a branch

```bash
git checkout -b <branchName> <tagName>
```

## 7. Git Aliases

```bash
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
git config --global alias.st status
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
# if you want an extra command, rather than a Git subcommand, start it with '!'
git config --global alias.visual '!gitk'
```
