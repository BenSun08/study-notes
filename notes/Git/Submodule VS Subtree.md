---
title: "Git: Submodule VS Subtree"
author: "San Wang"
date: "2022-03-17"
---

## Comparisons

1. Submodule keeps the **refererence** to the repo, while Subtree keeps the **copy** of the subrepo.

## Submodule

### Basics

It places a subrepository in a directory of the parent repository, using *.gitsubmodule* file to record the **path of the subrepository** where it placed and the **remote repository and branch** the subrepository tracks.
***

### Usage

#### `add` (add a submodule to the project)

`git submodule add [-b <branch>] [--] <repository> [<path>]`
where *-b* set the remote branch the subpository tracks, if it wasn't set, it would track the *detached HEAD* of the submodule's origin repository;
*repository* is the URL of the submodule repositoryl;
*path* is the relative path of the cloned submodule exist in the parent repository.
All this information will be recorded in the **.gitsubmodule** file.

If you want to change the branch the submodule track, you can use this command:
`git submodule set-branch (-b | --branch) <branch> [--] <path>`

#### `add`

#### `init`, `update`

If you clone a project which already has submodules, you would only have an empty directory of the submodule. You need to initialize it:
`git submodule init`
and let keep track of the remote repository:
`git submodule update`
or you can just combine them:
`git submodule update --init`

#### Make changes in submodule

You just need to get into the directory of the submodule and go through the normal process:
`pull`, `add`, `commit`, `push` .etc.
Every time you push changes in submodule, you need to update in the parent repository.
***

## Subtree

### Basics

When a subtree added in the repository, the *copy* of the subtree's remote repository is placed in the specified path.
***

### Usages

#### `add`

`git subtree add --prefix <path> <remote> <branch> [--squash]`
You can use this command to clone a subrepository in the specified path of the parent repository. *--squash* means just cloning the latest commit of the branch, ignoring the other
commit history.

#### Update from Upstream

If you want to keep track of the latest update in subtree, you can use this command in the parent repo:
`git subtree pull --prefix <path> <remote> <branch> [--squash]`

#### Publish Changes to Subtree in Parent Repo

If you make changes to subtree in the parent repository, and you want to *push* this change to the subtree's remote, use this command:
`git subtree push --prefix <path> <remote> <branch> [--squash]`
