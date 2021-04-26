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

### Pushing

```bash
git push <remote> <branch_name>:[<remote_branch_name>]
```

**Note**:
