# Git Branching

## 1. Branches in a Nutshell

- Git store data as a series of **snapshots**
- When a commit made, Git stores a commit object that contains a pointer to the snapshot of the content you staged, author's information, the commit message and pointer to its parent or parents.
- Staging the files computes a checksum for each one, stores that version of file in the Git Repository as **blobs**.

![A commit and its tree](./images/commit-and-tree.png)

### Creating a New Branch

```bash
git branch <branch_name>

git log --oneline --decoreate # show where the branch poniters are pointing to
```

This command **creates** a branch, but does not switch to that branch.
> Git keeps a special pointer call `HEAD` referring to the branch currently on.
![branched and commit history](./images/branch-and-history.png)

### Switching Branches

```bash
git checkout <branch_name>

git log --all # git log just list commits history on current branch, --all list all commits on all branches
```

> #### Composition
>
> ```bash
> git checkout -b <new_branch_name>
> ```
>
> #### For Git version 2.23
>
> ```bash
> git switch <branch_name>
> git switch -c <new_branch_name>
> git switch --create <new_branch_name>
> ```

## 2. Basic Branching and Merging

- If the branch merged in was directly ahead of the current branch's latest commit, Git simply move the pointer forward.(*fast-forward*)
- If development history has diverged from some older point, git create a new snapshot that results from the *three-way merge*, using the snapshot to merge in, the snapshot to merge into and the common ancestor, and automatically creates a new commit that points to it.

```bash
git merge <branch_name>
```

### Basic Merge Conflcts

If there are conflicts when branches merging, Git won't automatically creat a new merge commit. It has paused the process while you resolve the conflict.

## 3. Branch Management

```bash
git branch [--all] ## list of branches
git branch -v # to see the last commit on each branch
git branch --merged/--no-merged 
git branch -d/--delete <branch_name> # delete a branch
```

### Changing a Branch Name

```bash
git branch --move <old_branch_name> <new_branch_name> # only change locally
# push to remote
git push --set-upstream <remote> <new_branch_name>
```

## 4. Branching Workflows

### Long-Running Branches

### Topic Branches

## 5. Remote Branches

```bash
git fetch <remote> # fetch any data you don't have from remote  
```

**Note**: when you do a fetch that bring down new remote-tracking branches, you don't automatically have local, editable copies of them. you can:

```bash
git merge <remote>/<branch_name> # into your working branch or
git checkout -b <branch_name> <remote>/<branch_name>
```

### Pushing

```bash
git push <remote> <branch_name>:[<remote_branch_name>]
```

### Tracking Branches

Checking out a local branch from a remote-traking branch automatically creates a new branch called **tracking branch**. And the branch it tracks is called **upstream branch**.

```bash
git checkout --track <remote>/<branch_name> # create a new local branch named <branch_name> 
git branch -u/--set-upstrem-to <remote>/<branch_name> # set the current working branch to track <remote>/<branch_name>
git branch -vv # all tracking branches you have set up. This command doesn't reach out to server, it's telling you about what it has cached from last time you fetched from server.
```

### Pulling

a `git fetch` immediately followed by a `git merge`

### Deleting Remote Branched

```bash
git push <remote> -d/--delete <branch_name>
```

## 6. Rebasing

### Basic Rebase

```bash
git checkout experiment
git rebase master
```

This command works by going to the common ancestor of the two branch(the branch you're on and the branch you're rebasing onto), getting the diffs introduced by each commit and saving those diffs in temporary files, resetting the current  branch to the same commit as the branch you're rebasing onto, and finally applying each change in turn.
![Rebase](./images/basic-rebase.png)

### Advanced Rebase

```bash
git checkout --onto master server client
```

This command works by taking the `client` branch, figuring out the patches since it diverged from the `server` branch and replaying these patches in `client` branch as if it was based directly off the `master` branch instead.
![Advanced Rebase](./images/interesting-rebase.png)

```bash
git rebase master server
```

![Advanced Reabse 2](./images/interesting-rebase-2.png)

### The Perils of Rebasing

**Do not rebase commits that exist outside your repository and that people may have based work on.**
When other rebase branch that you are basing on, you can:

```bash
git pull --rebase
```

which equal to

```bash
git fetch
git rebase <remote>/<branch>
```
