// Copyright(C) 2023 InfiniFlow, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

module;

export module logical_planner;

import stl;

import query_context;
import bind_context;
import load_meta;
import logical_node;
import status;
import internal_types;
import base_statement;
import select_statement;
import copy_statement;
import insert_statement;
import create_statement;
import drop_statement;
import show_statement;
import flush_statement;
import optimize_statement;
import update_statement;
import delete_statement;
import prepare_statement;
import execute_statement;
import alter_statement;
import explain_statement;
import command_statement;
import data_type;

namespace infinity {

export class LogicalPlanner {
public:
    explicit LogicalPlanner(QueryContext *query_context_ptr) : query_context_ptr_(query_context_ptr) {
        names_ptr_ = MakeShared<Vector<String>>();
        types_ptr_ = MakeShared<Vector<DataType>>();
    }

    Status Build(const BaseStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildSelect(const SelectStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildInsert(const InsertStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildInsertValue(const InsertStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildInsertSelect(const InsertStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Update operator
    Status BuildUpdate(const UpdateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Delete operator
    Status BuildDelete(const DeleteStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Create operator
    Status BuildCreate(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCreateDatabase(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCreateTable(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCreateCollection(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCreateView(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCreateIndex(const CreateStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Drop operator
    Status BuildDrop(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildDropTable(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildDropCollection(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildDropSchema(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildDropIndex(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildDropView(const DropStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Prepare operator
    Status BuildPrepare(const PrepareStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Execute operator
    Status BuildExecute(const ExecuteStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCopy(const CopyStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Export operator
    Status BuildExport(const CopyStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Import operator
    Status BuildImport(const CopyStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Alter operator
    Status BuildAlter(const AlterStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Show operator
    Status BuildShow(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowColumns(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowSegments(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowIndexes(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowTables(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowViews(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowDatabases(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowConfigs(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowProfiles(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowSessionStatus(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowGlobalStatus(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildShowVar(const ShowStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Flush
    Status BuildFlush(const FlushStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildFlushData(const FlushStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildFlushLog(const FlushStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildFlushBuffer(const FlushStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Optimize
    Status BuildOptimize(const OptimizeStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    Status BuildCommand(const CommandStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    // Explain
    Status BuildExplain(const ExplainStatement *statement, SharedPtr<BindContext> &bind_context_ptr);

    [[nodiscard]] SharedPtr<LogicalNode> LogicalPlan() const { return logical_plan_; }

private:
    static Status ValidIdentifier(const String &identifier);

    QueryContext *query_context_ptr_{};

    SharedPtr<Vector<String>> names_ptr_{};
    SharedPtr<Vector<DataType>> types_ptr_{};
    SharedPtr<LogicalNode> logical_plan_{};
};

} // namespace infinity
